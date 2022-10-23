#pragma once
#include "SpriteObj.h"
#include <list>

class MechDrop : public SpriteObj
{
protected:
	Sprite deployArrow;
	Sprite deployXmark;

	Sprite mech;
	Sprite mechOutline;

	Vector2f arrowPoseFix;
	Vector2f xMarkPoseFix;
	Vector2f mechPoseFix;

	bool mechDroppable;
public:
	MechDrop(bool mechDroppable);
	virtual ~MechDrop();
	virtual void SetPos(const Vector2f& pos);
	virtual void Update(float dt) {}
	virtual void Draw(RenderWindow& window);
public:
	void SetTex(Sprite* sprite, String id);
	void SetSprites();
	
};

