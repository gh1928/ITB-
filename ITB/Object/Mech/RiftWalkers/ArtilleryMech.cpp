#include "ArtilleryMech.h"

ArtilleryMech::ArtilleryMech()
{
	type = MechClass::Range;
	SetTexture(*RESOURCE_MGR->GetTexture("graphics/mech/artillery/mech_artillery.png"));
	sprite.setOrigin(-11.f, 2.f);
}

ArtilleryMech::~ArtilleryMech()
{
}
