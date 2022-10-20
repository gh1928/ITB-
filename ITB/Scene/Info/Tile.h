#pragma once
#include "../../Object/Object.h"
#include "../../Framework/EnumClasses.h"
class Tile
{
protected:
	Object* obj;
	TileTypes type;
public:
	void SetType(TileTypes type) { this->type = type; }
	TileTypes GetType() { return type; }

	void SetObject(Object* obj) { this->obj = obj; }
	Object* GetObject() { return obj; }
};

