#pragma once
#include "Scene.h"
#include <vector>
#include "Info/MapInfo.h"
#include "../Object/SpriteObj.h"

class DevScene : public Scene
{
protected:
	array<array<SpriteObj*, 8>, 8> drawMap;
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
