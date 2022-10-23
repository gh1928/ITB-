#pragma once
#include "Object.h"
#include "../Framework/Utils.h"
#include "../Manager/ResourceMgr.h"

class SpriteObj : public Object
{
protected:
	Sprite sprite;	
	float speed;
public:
	SpriteObj();
	virtual ~SpriteObj();

	void SetOrigin(Origins origin);
	virtual void SetPos(const Vector2f& pos);

	virtual void Update(float dt){}
	virtual void Draw(RenderWindow& window);

	void SetTexture(Texture& tex);
	Sprite* GetSprite() { return &sprite; }
};

