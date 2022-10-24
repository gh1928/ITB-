#pragma once
#include "../SpriteObj.h"
#include "../../Framework/EnumClasses.h"

class SelectionCheck : public SpriteObj
{
protected:
	Vector2f localCenterPos;
	bool& isCursor;
	GamePhase& phase;
public:
	SelectionCheck(bool& isCursor, GamePhase& phase);
	virtual ~SelectionCheck(){}

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
public:
	void UpdateStartPhase(float dt);
};

