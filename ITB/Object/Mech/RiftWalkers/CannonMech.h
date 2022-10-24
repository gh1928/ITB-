#pragma once
#include "../Mech.h"
class CannonMech : public Mech
{
protected:

public:
	CannonMech(GamePhase& phase);
	virtual ~CannonMech();
public:
	virtual void SetAnim();

	virtual void Update(float dt);
	virtual void DeployPhaseUpdate(float dt);
};

