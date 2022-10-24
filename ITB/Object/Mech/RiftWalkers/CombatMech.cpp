#include "CombatMech.h"

CombatMech::CombatMech(GamePhase& phase)
	:Mech(phase)
{	
	type = MechClass::Prime;
	origin = { -10.f, 30.f + 2.f };
	
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

	animation.SetOrigin(origin);

	if (origin.y == 2.f)
		return;

	Vector2f trans = { 0, -dt * 60.f };
	origin += trans;
	if (origin.y < 2.f)
		origin = { -10.f, 2.f };
}
