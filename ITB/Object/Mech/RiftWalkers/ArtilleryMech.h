#pragma once
#include "../Mech.h"
class ArtilleryMech : public Mech
{
protected:
	float phaseTrigger;
public:
	ArtilleryMech(GamePhase& phase);
	virtual ~ArtilleryMech();
public:
	virtual void SetAnim();	
	virtual void Update(float dt);
	virtual void DeployPhaseUpdate(float dt);
};

