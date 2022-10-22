#pragma once
#include "../InteractiveObject.h"
#include "../../Framework/EnumClasses.h"
class Mech : public InteractiveObject
{
protected:
	MechClass type;
	int move;

public:
	~Mech(){}
};

