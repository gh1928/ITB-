#pragma once
#include "../SpriteObj.h"
#include "../../Framework/EnumClasses.h"

class StartPhaseUI : public SpriteObj
{
protected:
	IntRect checkBox;
	GamePhase& phase;
public:
	StartPhaseUI(GamePhase& phase);
	virtual ~StartPhaseUI();
	
	virtual void Draw(RenderWindow& window);
public:
	void ChangeTex();
	void PhaseEnd();
};

