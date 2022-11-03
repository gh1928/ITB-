#include "ArtilleryMech.h"

ArtilleryMech::ArtilleryMech(GamePhase& phase)
	:Mech(phase)
{
	type = MechClass::Range;
	origin = { -11.f, 2.f };
	phaseTrigger = 1.f;
	animation.SetOrigin(origin);
	move = 3;

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

void ArtilleryMech::Update(float dt)
{
	Mech::Update(dt);
	DeployPhaseUpdate(dt);
}

void ArtilleryMech::DeployPhaseUpdate(float dt)
{
	if (phase != GamePhase::Deploy)
		return;

	phaseTrigger -= dt;

	if (phaseTrigger < 0)
		phase = GamePhase::Player;		
}
