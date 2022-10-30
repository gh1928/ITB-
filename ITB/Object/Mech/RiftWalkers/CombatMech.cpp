#include "CombatMech.h"

CombatMech::CombatMech(GamePhase& phase)
	:Mech(phase)
{	
	type = MechClass::Prime;
	origin = { -10.f, 2.f };
	animation.SetOrigin(origin);
	
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

void CombatMech::Update(float dt)
{
	Mech::Update(dt);
	DeployPhaseUpdate(dt);
}

void CombatMech::DeployPhaseUpdate(float dt)
{
	if (phase != GamePhase::Deploy)
		return;
}
