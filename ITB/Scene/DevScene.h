#pragma once
#include "Scene.h"
#include "Info/MapInfo.h"
#include "../Object/SpriteObj.h"
#include "../Object/InteractiveObject.h"

class DevScene : public Scene
{
protected:
	array<Sprite, 82> backGround;	

	
	array<array<list<SpriteObj*>, 8>, 8> drawMap;

	array<array<list<Object*>*, 8>, 8> objs;
	array<array<list<InteractiveObject*>*, 8>, 8> actObjs;
	array<array<list<Object*>*, 8>, 8> uiObjs;	

	array<array<list<Mech*>*, 8>, 8> mechs;
	array<array<list<Vek*>*, 8>, 8> veks;


	list<Object*> sceneUi;
	Vector2f uiULpos;
	Vector2f uiMidPos;

	MapInfo mapInfo;
	GamePhase phase;

	bool isNewPhase;
	bool isPhaseStart;
	float uiTimer;
public:
	DevScene();
	virtual ~DevScene();

	virtual void Init();
	virtual void Release();

	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
public:
	void MakeBackground();
	void SetTileTex(int i, int j);

	void InitStartPhase();
	void UpdateStartPhase(float dt);
	void UpdatePlayerPhase(float dt);
};
