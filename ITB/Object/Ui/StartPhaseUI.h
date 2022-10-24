#pragma once
#include "../SpriteObj.h"

class StartPhaseUI : public SpriteObj
{
protected:
	IntRect checkBox;

public:
	StartPhaseUI();
	virtual ~StartPhaseUI();
	
	virtual void Draw(RenderWindow& window);
public:
	void ChangeTex();
};

