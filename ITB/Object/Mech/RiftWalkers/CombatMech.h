#pragma once
#include "../Mech.h"

class CombatMech : public Mech
{
protected:

public:
	CombatMech(GamePhase& phase);
	virtual ~CombatMech();
public:
	virtual void SetAnim();

	virtual void Update(float dt);
	virtual void DeployPhaseUpdate(float dt);	
};

