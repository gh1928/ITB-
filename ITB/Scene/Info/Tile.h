#pragma once
#include "../../Object/Object.h"
#include "../../Framework/EnumClasses.h"
#include <list>
#include "../../Manager/InputMgr.h"
#include "../../Object/InteractiveObject.h"
#include "../../Framework/GameObjectsHeader.h"

class Scene;
class Tile
{
protected:	
	Scene* scene;
	static int tileCount;	
	int indexI;
	int indexJ;

	static int mechCount;

	bool isCursor;

	list<Object*> objList;	
	list<InteractiveObject*> actObjList;

	TileTypes type;

	Vector2f position;

	GamePhase phase;
public:
	Tile();
	~Tile();
public:
	void Init(Scene* scene);

	void SetType(TileTypes type) { this->type = type; }
	TileTypes GetType() { return type; }

	void SetPos(Vector2f pos);
	Vector2f GetPos() { return position; }
		
	void AddObject(Object* obj) { objList.push_back(obj); }
	void AddActObject(InteractiveObject* iobj) { actObjList.push_back(iobj); }
	list<Object*>* GetObjList() { return &objList; }
	list<InteractiveObject*>* GetActObjList() { return &actObjList; }

	void Update(float dt);

public:
	void UpdateStartPhase(float dt);
	void SetStartObject();
	void MechDrop();
	
	
	
	void SetPhase(GamePhase phase) { this->phase = phase; }	
	GamePhase GetPhase() { return phase; }
	
};

