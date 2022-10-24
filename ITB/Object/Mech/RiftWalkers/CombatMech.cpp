#include "CombatMech.h"

CombatMech::CombatMech(GamePhase& phase)
	:Mech(phase)
{	
	type = MechClass::Prime;
	origin = { -10.f, 30.f + 2.f };
	//origin = { -10.f, 2.f };
	SetAnim();	
}

CombatMech::~CombatMech()
{
}

void CombatMech::SetAnim()
{
	Mech::SetAnim();
	animation.SetTexture("graphics/mech/combat/mech_punch_a.png", 4);
}
