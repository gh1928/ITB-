#pragma once
#include "../../Object/Object.h"
#include "../../Framework/EnumClasses.h"
#include <list>
#include "../../Manager/InputMgr.h"
#include "../../Object/SelectionCheck.h"
#include "../../Object/Mech/RiftWalkers/CombatMech.h"

class Tile
{
protected:
	list<Object*> tObjList;	
	TileTypes type;

	Vector2f position;
	Vector2f centerPos;
	Vector2f localCenterPos;

	SelectionCheck* selectionCheck;

public:
	~Tile();
public:
	void Init();

	void SetType(TileTypes type) { this->type = type; }
	TileTypes GetType() { return type; }

	void SetPos(Vector2f pos);
	Vector2f GetPos() { return position; }
		
	void AddObject(Object* obj) { tObjList.push_back(obj); }
	list<Object*>* GetObjList() { return &tObjList; }

	void Update(float dt);
	void MechDrop();
};

