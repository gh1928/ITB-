#pragma once
#include "SpriteObj.h"
class SelectionCheck : public SpriteObj
{
protected:
	Vector2f localCenterPos;
	bool& isCursor;
public:
	SelectionCheck(bool& isCursor);
	virtual ~SelectionCheck(){}

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
};

