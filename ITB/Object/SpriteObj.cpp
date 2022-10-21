#include "SpriteObj.h"

SpriteObj::SpriteObj()	
{
}

SpriteObj::~SpriteObj()
{
}

void SpriteObj::SetOrigin(Origins origin)
{
	Utils::SetOrigin(sprite, origin);
}

void SpriteObj::SetPos(const Vector2f& pos)
{
	Object::SetPos(pos);
	sprite.setPosition(pos);
}

void SpriteObj::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

void SpriteObj::SetTexture(Texture& tex)
{
	sprite.setTexture(tex);
	sprite.setScale({ 2,2 });
}
