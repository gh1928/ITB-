#pragma once
#include "Scene.h"
class DevScene2 : public Scene
{
protected:



public:
	DevScene2():Scene(Scenes::DevScene2){}
	virtual void Init();
	virtual void Enter(){};
	virtual void Exit(){};
};

