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
	
	deployChecked = false;

	if ((1 <= indexI && indexI <= 6) && (1 <= indexJ && indexJ <= 3))
	{
		if (type == TileTypes::Stand || type == TileTypes::Water)
			uiObjList.push_back(new FillStartPos);		
	}

	SetStartObject();

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
	isMechSpace = actObjList.empty() ? true : false;	

	//UpdateNode();

	UpdateStartPhase(dt);		
	UpdateDeployPhase(dt);

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
			&& isMechSpace) ? true : false;	

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
			uiObjList.push_front(new MechDrop(true));
			uiObjList.front()->SetPos(position);
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


void Tile::UpNodeUpdate()
{	
	upNode = mapInfo->TileSpace(indexI, indexJ - 1);
}

void Tile::LNodeUpdate()
{	
	lfNode = mapInfo->TileSpace(indexI + 1, indexJ);
}

void Tile::RNodeUpdate()
{
	rtNode = mapInfo->TileSpace(indexI - 1, indexJ);
}

void Tile::DnNodeUpdate()
{
	dnNode = mapInfo->TileSpace(indexI, indexJ + 1);
}

void Tile::UpdateNode()
{
	UpNodeUpdate();
	LNodeUpdate();
	RNodeUpdate();
	DnNodeUpdate();
}
