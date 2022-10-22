#include "Tile.h"
#include "../../Framework/Utils.h"
#include <iostream>
#include "../../Manager/ResourceMgr.h"
#include "../../Object/FillStartPos.h"

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
	for (auto obj : tObjList)
	{
		if(obj != nullptr)
			delete obj;	
	}
	tObjList.clear();
}

void Tile::Init()
{	
	if ((1 <= indexI && indexI <= 6) && ( 1 <= indexJ && indexJ <= 3 ))
	{
		if (type == TileTypes::Stand || type == TileTypes::Water)			
			tObjList.push_back(new FillStartPos);
	}

	tObjList.push_back(new SelectionCheck(isCursor));

	for (auto obj : tObjList)
	{
		obj->Init();
	}

	for (auto obj : tIObjList)
	{
		obj->Init();
	}

	phase = GamePhase::Start;
}

void Tile::SetPos(Vector2f pos)
{
	position = pos;
	for (auto obj : tObjList)
	{
		obj->SetPos(position);
	}		
}

void Tile::Update(float dt)
{	
	if(phase == GamePhase::Start)
		UpdateStartPhase(dt);

	for (auto obj : tObjList)
	{
		if(obj->GetActive())
			obj->Update(dt);
	}

	for (auto obj : tIObjList)
	{
		if (obj->GetActive())
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

	if (!tIObjList.empty())
	{

	}
}

void Tile::MechDrop()
{	
	if (mechCount > 2)
		return;

	switch (++mechCount)
	{
	case 0:
		tIObjList.push_back(new CombatMech);
		tIObjList.back()->SetPos(position);
		break;
	case 1:
		tIObjList.push_back(new CannonMech);
		tIObjList.back()->SetPos(position);
		break;
	case 2:
		tIObjList.push_back(new ArtilleryMech);
		tIObjList.back()->SetPos(position);
		break;
	}
}
