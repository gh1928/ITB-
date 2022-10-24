#pragma once
#include "../Mech.h"
class ArtilleryMech : public Mech
{
protected:
public:
	ArtilleryMech(GamePhase& phase);
	virtual ~ArtilleryMech();
public:
	virtual void SetAnim();
};

