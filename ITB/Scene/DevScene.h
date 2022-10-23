#pragma once
#include "Scene.h"
#include "Info/MapInfo.h"
#include "../Object/SpriteObj.h"
#include "../Object/InteractiveObject.h"

class DevScene : public Scene
{
protected:
	array<Sprite, 82> backGround;	

	array<array<SpriteObj*, 8>, 8> drawMap;

	array<array<list<Object*>*, 8>, 8> objs;
	array<array<list<InteractiveObject*>*, 8>, 8> actObjs;
	array<array<list<Object*>*, 8>, 8> uiObjs;

	list<Object*> sceneUi;
	Vector2f uiULpos;

	MapInfo mapInfo;
	GamePhase phase;
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
};
