#pragma once
#include "../SpriteObj.h"
class MiddleBar : public SpriteObj
{
protected:
	GamePhase& phase;
public:
	MiddleBar(GamePhase& phase);
	virtual ~MiddleBar(){}

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
};

