#include "ArtilleryMech.h"

ArtilleryMech::ArtilleryMech(GamePhase& phase)
	:Mech(phase)
{
	type = MechClass::Range;
	origin = { -11.f, 30.f + 2.f };
	phaseTrigger = 0.5f;
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

	animation.SetOrigin(origin);

	if (origin.y == 2.f)
		phaseTrigger -= dt;

	if (phaseTrigger < 0)
		phase = GamePhase::Player;		

	Vector2f trans = { 0, -dt * 40.f };
	
	origin += trans;
	if (origin.y < 2.f)
		origin = { -11.f, 2.f };
}
