#include "Mech.h"

void Mech::SetAnim()
{
	animation.SetSpriteObj(this, AnimationType::Actor);
	animation.SetOrigin(origin);	
	animation.SetEndTime(0.5f);
}

void Mech::Update(float dt)
{
	animation.UpdateAnimation(dt);
}
