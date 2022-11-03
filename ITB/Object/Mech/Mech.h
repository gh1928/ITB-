#pragma once
#include "../InteractiveObject.h"
#include "../../Framework/EnumClasses.h"
#include "../../Framework/Animator.h"

class Mech : public InteractiveObject
{
protected:
	MechClass type;
	int move;
	GamePhase& phase;

	IntRect texRect;
	Vector2f origin;

	Animator animation;

public:	
	Mech(GamePhase& phase);
	virtual ~Mech(){}

	virtual void SetAnim();
	virtual void Update(float dt);
public:
	virtual void DeployPhaseUpdate(float dt);
	virtual int GetMove() { return move; }
};

