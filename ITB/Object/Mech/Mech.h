#pragma once
#include "../InteractiveObject.h"
#include "../../Framework/EnumClasses.h"
#include "../../Framework/Animator.h"

class Mech : public InteractiveObject
{
protected:
	MechClass type;
	int move;

	IntRect texRect;
	Vector2f origin;

	Animator animation;
public:	
	virtual ~Mech(){}

	virtual void SetAnim();
	virtual void Update(float dt);
};

