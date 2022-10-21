#include "Tile.h"
#include "../../Framework/Utils.h"
#include <iostream>
#include "../../Manager/ResourceMgr.h"

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
	selectionCheck = new SelectionCheck;
	selectionCheck->SetTexture(*RESOURCE_MGR->GetTexture("graphics/ui/tilesel.png"));	
	selectionCheck->SetActive(false);
	tObjList.push_back(selectionCheck);
	localCenterPos = Vector2f{ 56.f, 42.f };
}

void Tile::SetPos(Vector2f pos)
{
	position = pos;
	selectionCheck->SetPos(position);
	centerPos = position + Vector2f{ 56.f, 42.f };	
}

void Tile::Update(float dt)
{	
	Vector2f mousePos = InputMgr::GetMousePos();
	mousePos -= position;

	selectionCheck->SetActive((abs(localCenterPos.x - mousePos.x) / localCenterPos.x + abs(localCenterPos.y - mousePos.y) / localCenterPos.y) <1.f);
	
	if (selectionCheck->GetActive())
	{
		if (InputMgr::GetMouseButtonDown(Mouse::Left))
		{
			MechDrop();
		}
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
