#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::Release()
{
}

void Object::Translate(const Vector2f& delta)
{
    SetPos(position + delta);
}