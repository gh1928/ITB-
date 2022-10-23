#pragma once
#include "../InteractiveObject.h"
class Building : public InteractiveObject
{
protected:
	Sprite grass;
	IntRect texRect;
	Vector2f b1Origin;
	Vector2f grsOrigin;
public:
	Building();
	~Building();

	virtual void SetPos(const Vector2f& pos);
	virtual void Draw(RenderWindow& window);
};

