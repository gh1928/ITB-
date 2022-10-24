#pragma once
#include "../SpriteObj.h"
class MouseUi : public SpriteObj
{
protected:
public:
	MouseUi();
	~MouseUi();

	virtual void Update(float dt);
};

