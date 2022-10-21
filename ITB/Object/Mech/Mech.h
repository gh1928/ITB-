#pragma once
#include "../SpriteObj.h"
#include "../../Framework/EnumClasses.h"
class Mech : public SpriteObj
{
protected:
	MechClass type;

	int maxHp;
	int hp;

	int move;

public:
	~Mech(){}
};

