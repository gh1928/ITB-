#pragma once
#include "Scene.h"
#include <vector>
#include <list>
#include "Info/MapInfo.h"
#include "../Object/SpriteObj.h"
#include "../Object/InteractiveObject.h"

class DevScene : public Scene
{
protected:
	array<Sprite, 82> backGround;	

	array<array<SpriteObj*, 8>, 8> drawMap;
	array<array<list<Object*>*, 8>, 8> drawObject;
	array<array<list<InteractiveObject*>*, 8>, 8> drawIObject;
	
	MapInfo mapInfo;
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

	void UpdateStartPhase(float dt);
};
