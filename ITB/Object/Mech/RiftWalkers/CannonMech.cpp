#include "CannonMech.h"

CannonMech::CannonMech(GamePhase& phase)
	:Mech(phase)
{	
	type = MechClass::Brute;	
	origin = { -12.f, - 7.f };
	animation.SetOrigin(origin);

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

void CannonMech::Update(float dt)
{
	Mech::Update(dt);
	DeployPhaseUpdate(dt);
}

void CannonMech::DeployPhaseUpdate(float dt)
{
	if (phase != GamePhase::Deploy)
		return;
}
