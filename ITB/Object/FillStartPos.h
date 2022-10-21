#pragma once
#include "SpriteObj.h"
class FillStartPos :  public SpriteObj
{
protected:
public:
	FillStartPos();
	virtual ~FillStartPos(){}

	virtual void Update(float dt);
};

