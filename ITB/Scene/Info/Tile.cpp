#include "Tile.h"
#include "../../Framework/Utils.h"
#include <iostream>
#include "../../Manager/ResourceMgr.h"
#include "../../Scene/Scene.h"
#include "../Info/MapInfo.h"
int Tile::tileCount = -1;
int Tile::mechCount = -1;

Tile::Tile()
{
	tileCount += 1;
	int index = tileCount % 64;
	indexI = index / 8;
	indexJ = index % 8;
	nodeInfo = 0;
}

Tile::~Tile()
{
	for (auto obj : objList)
	{
		if(obj != nullptr)
			delete obj;	
	}
	objList.clear();

	for (auto obj : actObjList)
	{
		if (obj != nullptr)
			delete obj;
	}
	actObjList.clear();	

	for (auto obj : uiObjList)
	{
		if (obj != nullptr)
			delete obj;
	}
	uiObjList.clear();

	for (auto obj : mechList)
	{
		if (obj != nullptr)
			delete obj;
	}
	mechList.clear();

	for (auto obj : vekList)
	{
		if (obj != nullptr)
			delete obj;
	}
	vekList.clear();
}

void Tile::Init(Scene* scene, MapInfo* mapInfo)
{	
	this->scene = scene;
	this->mapInfo = mapInfo;	
	this->phase = this->mapInfo->GetPhase();
	
	chekingObject = mapInfo->GetChekingObject();
	deployChecked = false;

	if ((1 <= indexI && indexI <= 6) && (1 <= indexJ && indexJ <= 3))
	{
		if (type == TileTypes::Stand || type == TileTypes::Water)
			uiObjList.push_back(new FillStartPos);		
	}

	SetStartObject();

	objList.push_back(new MoveCheck);
	objList.push_back(new SelectionCheck(isCursor, *this->phase));
	
	for (auto obj : objList)
	{
		obj->Init();
	}

	for (auto obj : actObjList)
	{
		obj->Init();
	}
}

void Tile::SetPos(Vector2f pos)
{
	position = pos;
	for (auto obj : objList)
	{
		obj->SetPos(position);
	}		
}

void Tile::Update(float dt)
{	
	isMechSpace = (actObjList.empty() && vekList.empty()) ? true : false;			

	UpdateStartPhase(dt);	
	UpdateDeployPhase(dt);
	UpdatePlayerPhase(dt);
	UpdateMovePhase(dt);

	ObjUpdate(dt);
}

void Tile::ObjUpdate(float dt)
{
	for (auto obj : objList)
	{
		if (obj->GetActive())
			obj->Update(dt);
	}

	for (auto obj : actObjList)
	{
		if (obj->GetActive())
		{
			obj->SetPos(position);
			obj->Update(dt);
		}
	}

	for (auto obj : uiObjList)
	{
		if (obj->GetActive())
			obj->Update(dt);
	}

	for (auto obj : mechList)
	{
		if (obj->GetActive())
		{
			if (*phase == GamePhase::Deploy)
				continue;
			obj->SetPos(position);

			obj->Update(dt);
		}
	}

	for (auto obj : vekList)
	{
		if (obj->GetActive())
		{
			obj->SetPos(position);
			obj->Update(dt);
		}
	}
}

void Tile::UpdateStartPhase(float dt)
{
	for (auto ui : uiObjList)
	{
		uiObjList.back()->SetPos(position);
	}

	if (*phase != GamePhase::Start)
		return;	

	mechDroppable =
		      ((1 <= indexI && indexI <= 6)
			&& (1 <= indexJ && indexJ <= 3)
			&& isMechSpace && mechList.empty()) ? true : false;	

	if (isCursor && !deployChecked)
	{		
		uiObjList.push_back(new MechDrop(mechDroppable));		
		deployChecked = true;
	}

	if (!isCursor && deployChecked)
	{
		delete uiObjList.back();
		uiObjList.pop_back();
		deployChecked = false;
	}

	if (InputMgr::GetMouseButtonDown(Mouse::Left))
	{
		if (mechDroppable && isCursor)
		{
			uiObjList.push_back(new MechDrop(true));
			uiObjList.back()->SetPos(position);
			MechDropEvent();
		}
	}
}

void Tile::UpdateDeployPhase(float dt)
{
	if (*phase != GamePhase::Deploy)
		return;

	Vector2f trans = { 0, 400.f };

	for (auto obj : mechList)
	{
		if (obj->GetActive())
		{
			obj->Update(dt);
			if (obj->GetPos() == position)
				continue;
			{
				obj->SetPos(obj->GetPos() + trans * dt);
				if (obj->GetPos().y > position.y)
					obj->SetPos(position);
			}			
		}
	}

	for (auto ptr : uiObjList)
	{
		if (ptr != nullptr)
			delete ptr;
	}
	uiObjList.clear();
}

void Tile::UpdatePlayerPhase(float dt)
{
	if (*phase != GamePhase::Player)
		return;	

	ShowMovePos();

	objList.front()->SetActive(nodeInfo ? true : false);
}

void Tile::UpdateMovePhase(float dt)
{
	if (*phase != GamePhase::Move)
		return;

	if (isCursor &&
		nodeInfo &&
		mechList.empty() &&
		InputMgr::GetMouseButtonDown(Mouse::Left))
	{
		Vector2i mechPos = mapInfo->GetPathList()->back();
		Mech* mech = mapInfo->GetTilesInfo(mechPos.x, mechPos.y).GetMechList()->front();
		mapInfo->GetTilesInfo(mechPos.x, mechPos.y).GetMechList()->pop_front();
		mechList.push_back(mech);
		*phase = GamePhase::Player;
	}
}

void Tile::SetStartObject()
{
	switch (type)
	{
	case TileTypes::Water:		
		break;
	case TileTypes::Mountain:
		actObjList.push_back(new Mountain);		
		break;
	case TileTypes::Building1:
		actObjList.push_back(new Building);
		break;
	default:
		break;
	}
}

void Tile::MechDropEvent()
{	
	if (mechCount >= 2)
		return;

	Vector2f beforeDeploy = { 0, -100.f };

	switch (++mechCount)
	{
	case 0:
		mechList.push_back(mapInfo->GetSqud(0));
		mechList.back()->SetPos(position + beforeDeploy);
		break;
	case 1:
		mechList.push_back(mapInfo->GetSqud(1));
		mechList.back()->SetPos(position + beforeDeploy);
		break;
	case 2:
		mechList.push_back(mapInfo->GetSqud(2));
		mechList.back()->SetPos(position + beforeDeploy);
		break;
	}
	mechList.back()->SetActive(false);
}

void Tile::ShowMovePos()
{
	if (isCursor && !mechList.empty())
	{
		FloodFill(indexI, indexJ, mechList.front()->GetMove() + 1);
		if (InputMgr::GetMouseButtonDown(Mouse::Left))
		{
			*phase = GamePhase::Move;
			mapInfo->GetPathList()->push_back({ indexI,indexJ });			
		}
	}
}

void Tile::FloodFill(int i, int j, int move)
{
	mapInfo->GetTilesInfo(i, j).SetNodeInfo(move);
	move--;

	if (j - 1 > -1 && 
		mapInfo->GetTilesInfo(i, j - 1).IsMechSpace() &&
		mapInfo->GetTilesInfo(i, j - 1).GetNodeInfo() < move )
		FloodFill(i, j - 1, move);

	if (i - 1 > -1 && 
		mapInfo->GetTilesInfo(i - 1, j).IsMechSpace() &&
		mapInfo->GetTilesInfo(i - 1, j).GetNodeInfo() < move )
		FloodFill(i - 1, j, move);

	if (i + 1 < 8 && 
		mapInfo->GetTilesInfo(i + 1, j).IsMechSpace() &&
		mapInfo->GetTilesInfo(i + 1, j).GetNodeInfo() < move )
		FloodFill(i + 1, j, move);

	if (j + 1 < 8 && 
		mapInfo->GetTilesInfo(i, j + 1).IsMechSpace() &&
		mapInfo->GetTilesInfo(i, j + 1).GetNodeInfo() < move )
		FloodFill(i, j + 1, move);
}
