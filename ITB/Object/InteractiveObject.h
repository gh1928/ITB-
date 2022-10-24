#pragma once
#include "SpriteObj.h"
class InteractiveObject : public SpriteObj
{
protected:
    ActorType actorType;
    int maxHp;
    int hp;
public:
    InteractiveObject(){}
    ~InteractiveObject(){}

    virtual ActorType GetActorType() { return actorType; }
};