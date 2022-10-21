#include "CombatMech.h"

CombatMech::CombatMech()
{
	type = MechClass::Prime;
	SetTexture(*RESOURCE_MGR->GetTexture("graphics/mech/combat/mech_punch.png"));	
	sprite.setOrigin(-10.f, 2.f);
}

CombatMech::~CombatMech()
{
}
