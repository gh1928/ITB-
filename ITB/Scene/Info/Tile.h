#pragma once
#include "../../Object/Object.h"
#include "../../Framework/EnumClasses.h"
#include <list>
#include "../../Manager/InputMgr.h"
#include "../../Object/InteractiveObject.h"
#include "../../Framework/GameObjectsHeader.h"

class Scene;
class MapInfo;

class Tile
{
protected:	
	Scene* scene;
	MapInfo* mapInfo;

	static int tileCount;	
	int indexI;
	int indexJ;

	static int mechCount;

	bool isCursor;
	bool isMechSpace;
	bool isVekSpace;

	bool mechDroppable;
	bool deployChecked;	

	list<Object*> objList;	
	list<InteractiveObject*> actObjList;
	list<Object*> uiObjList;

	list<Mech*> mechList;
	list<Vek*> vekList;
	

	array<Object*, 3>* squd;

	TileTypes type;

	Vector2f position;

	GamePhase* phase;

	bool upNode;
	bool lfNode;
	bool rtNode;
	bool dnNode;
public:
	Tile();
	~Tile();
public:
	void Init(Scene* scene, MapInfo* mapInfo);

	void SetType(TileTypes type) { this->type = type; }
	TileTypes GetType() { return type; }

	void SetPos(Vector2f pos);
	Vector2f GetPos() { return position; }
		
	void AddObject(Object* obj) { objList.push_back(obj); }
	void AddActObject(InteractiveObject* iobj) { actObjList.push_back(iobj); }
	list<Object*>* GetObjList() { return &objList; }
	list<InteractiveObject*>* GetActObjList() { return &actObjList; }
	list<Object*>* GetUiObjList() { return &uiObjList; }

	list<Mech*>* GetMechList() { return &mechList; }
	list<Vek*>* GetVeckList() { return &vekList; }

	void Update(float dt);
	void ObjUpdate(float dt);

public:
	void UpdateStartPhase(float dt);	
	void UpdateDeployPhase(float dt);
	void SetStartObject();
	void MechDropEvent();	
	
	void SetPhase(GamePhase phase) { *this->phase = phase; }	
	GamePhase GetPhase() { return *phase; }	

	static int GetMechCount() { return mechCount; }	
	bool IsSpace() { return isMechSpace; }
	
	void UpNodeUpdate();
	void LNodeUpdate();
	void RNodeUpdate();
	void DnNodeUpdate();

	void UpdateNode();
};

