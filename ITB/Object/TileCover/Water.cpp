#include "Water.h"

Water::Water()
{
	SetAnim();
	origin = { 0,0 };
}

Water::~Water()
{
}

void Water::SetAnim()
{
	animation.SetSpriteObj(this, AnimationType::Background);
	animation.SetOrigin(origin);
	animation.SetEndTime(0.3f);
	animation.SetTexture("graphics/tiles/water_anim.png",5);
}
