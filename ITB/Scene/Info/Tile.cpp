#include "Tile.h"
#include "../../Framework/Utils.h"
#include <iostream>
#include "../../Manager/ResourceMgr.h"
#include "../../Object/FillStartPos.h"

int Tile::tileCount = -1;

Tile::Tile()
{
	tileCount += 1;
	index = tileCount % 64;
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
	int i = index / 8;
	int j = index % 8;

	if ((1 <= i && i <= 6) && ( 1 <= j && j <= 3 ))
	{
		tObjList.push_back(new FillStartPos);
	}	

	tObjList.push_back(new SelectionCheck);

	for (auto obj : tObjList)
	{
		obj->Init();
	}
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
	Vector2f mousePos = InputMgr::GetMousePos();
	mousePos -= position;	

	if (InputMgr::GetMouseButtonDown(Mouse::Left))
	{
		MechDrop();
	}

	for (auto obj : tObjList)
	{
		if(obj->GetActive())
			obj->Update(dt);		
	}
}

void Tile::MechDrop()
{
	tObjList.push_back(new CombatMech);
	tObjList.back()->SetPos(position);
}
