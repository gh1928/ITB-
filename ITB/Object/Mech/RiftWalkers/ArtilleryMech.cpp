#include "ArtilleryMech.h"

ArtilleryMech::ArtilleryMech(GamePhase& phase)
	:Mech(phase)
{
	type = MechClass::Range;
	origin = { -11.f, 30.f + 2.f };
	//origin = { -11.f, 2.f };
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
