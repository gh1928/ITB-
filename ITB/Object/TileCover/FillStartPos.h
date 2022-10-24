#pragma once
#include "../SpriteObj.h"
#include "../../Framework/EnumClasses.h"
#include "../../Scene/Info/Tile.h"

class FillStartPos :  public SpriteObj
{
protected:
	bool isSpace;
public:
	FillStartPos();
	virtual ~FillStartPos(){}
		
	virtual void Init();

	bool SetSpaceCheck(bool isSpace) { this->isSpace = isSpace; }

	virtual void Update(float dt);

	virtual void Draw(RenderWindow& window);
};

