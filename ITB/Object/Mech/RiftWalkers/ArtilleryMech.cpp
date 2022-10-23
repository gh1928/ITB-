#include "ArtilleryMech.h"

ArtilleryMech::ArtilleryMech()
{
	type = MechClass::Range;
	origin = { -11.f, 2.f };
	SetAnim();
}

ArtilleryMech::~ArtilleryMech()
{
}

void ArtilleryMech::SetAnim()
{
	Mech::SetAnim();
	animation.SetTexture("graphics/mech/artillery/mech_artillery_a.png", 4);
}
