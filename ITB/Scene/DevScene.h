#pragma once
#include "Scene.h"
#include <vector>
#include <list>
#include "Info/MapInfo.h"
#include "../Object/SpriteObj.h"

class DevScene : public Scene
{
protected:
	array<array<SpriteObj*, 8>, 8> drawMap;
	array<array<list<Object*>*, 8>, 8> drawObject;
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
};
