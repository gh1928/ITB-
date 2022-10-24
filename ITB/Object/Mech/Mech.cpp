#include "Mech.h"

Mech::Mech(GamePhase& phase)
	:phase(phase)
{
	actorType = ActorType::Mech;
}

void Mech::SetAnim()
{
	animation.SetSpriteObj(this, AnimationType::Actor);
	animation.SetOrigin(origin);	
	animation.SetEndTime(0.5f);
}

void Mech::Update(float dt)
{
	animation.UpdateAnimation(dt);	
}

void Mech::DeployPhaseUpdate(float dt)
{
	if (phase != GamePhase::Deploy)
		return;	
}
