#include "CannonMech.h"

CannonMech::CannonMech(GamePhase& phase)
	:Mech(phase)
{	
	type = MechClass::Brute;	
	origin = { -12.f, 30.f - 7.f };
	//origin = { -12.f, -7.f };
	SetAnim();
}

CannonMech::~CannonMech()
{
}

void CannonMech::SetAnim()
{
	Mech::SetAnim();	
	animation.SetTexture("graphics/mech/cannon/mech_tank_a.png", 3);	
}
