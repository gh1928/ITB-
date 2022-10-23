#include "Tile.h"
#include "../../Framework/Utils.h"
#include <iostream>
#include "../../Manager/ResourceMgr.h"
#include "../../Scene/Scene.h"

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
}

void Tile::Init(Scene* scene)
{	
	this->scene = scene;

	if ((1 <= indexI && indexI <= 6) && ( 1 <= indexJ && indexJ <= 3 ))
	{
		if (type == TileTypes::Stand || type == TileTypes::Water)			
			objList.push_back(new FillStartPos);
	}

	SetStartObject();

	objList.push_back(new SelectionCheck(isCursor));

	for (auto obj : objList)
	{
		obj->Init();
	}

	for (auto obj : actObjList)
	{
		obj->Init();
	}

	phase = GamePhase::Start;
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
	if(phase == GamePhase::Start)
		UpdateStartPhase(dt);

	for (auto obj : objList)
	{
		if(obj->GetActive())
			obj->Update(dt);
	}

	for (auto obj : actObjList)
	{
		if (obj->GetActive())
			obj->SetPos(position);
			obj->Update(dt);
	}
}

void Tile::UpdateStartPhase(float dt)
{
	if (InputMgr::GetMouseButtonDown(Mouse::Left))
	{
		if ((1 <= indexI && indexI <= 6) && (1 <= indexJ && indexJ <= 3) && isCursor)
			MechDrop();
	}

	if (!actObjList.empty())
	{

	}
}

void Tile::SetStartObject()
{
	switch (type)
	{
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

void Tile::MechDrop()
{	
	if (mechCount > 2)
		return;

	switch (++mechCount)
	{
	case 0:
		actObjList.push_back(new CombatMech);		
		break;
	case 1:
		actObjList.push_back(new CannonMech);		
		break;
	case 2:
		actObjList.push_back(new ArtilleryMech);		
		break;
	}
}
