#pragma once
#include "SpriteObj.h"
class InteractiveObject : public SpriteObj
{
protected:
    int maxHp;
    int hp;
public:
    InteractiveObject(){};
    ~InteractiveObject(){};
};