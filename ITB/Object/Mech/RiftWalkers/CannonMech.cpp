#include "CannonMech.h"

CannonMech::CannonMech()
{
	type = MechClass::Brute;
	SetTexture(*RESOURCE_MGR->GetTexture("graphics/mech/cannon/mech_tank.png"));
	sprite.setOrigin(-12.f, -7.f);
}

CannonMech::~CannonMech()
{
}
