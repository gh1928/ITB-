#pragma once
#include "../../Object/Object.h"
#include "../../Framework/EnumClasses.h"
#include <list>
class Tile
{
protected:
	list<Object*> tObjList;	
	TileTypes type;
public:
	void SetType(TileTypes type) { this->type = type; }
	TileTypes GetType() { return type; }
		
	void AddObject(Object* obj) { tObjList.push_back(obj); }
	list<Object*>* GetObjList() { return &tObjList; }

	void Update(float dt);
};

