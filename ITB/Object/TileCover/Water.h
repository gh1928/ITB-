#pragma once
#include "../SpriteObj.h"
#include "../../Framework/Animator.h"

class Water : public SpriteObj
{
protected:
	Animator animation;
	Vector2f origin;
public:
	Water();
	virtual ~Water();
public:
	void SetAnim();
	virtual void Update(float dt) { animation.UpdateAnimation(dt); }
};

