#include "Building.h"

Building::Building()
{
	Vector2u size = RESOURCE_MGR->GetTexture("graphics/tiles/building_sheet.png")->getSize();
	texRect = { 0,0, (int)size.x/3, (int)size.y };

	SetTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/building_sheet.png"));
	sprite.setTextureRect(texRect);
	b1Origin = { -3.f, 8.f };
	sprite.setOrigin(b1Origin);
	
	grass.setTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/building_1_tile.png"));
	grass.setScale(2, 2);
	grsOrigin = { 0.f,15.f };
	grass.setOrigin(grsOrigin);
}

Building::~Building()
{
}

void Building::SetPos(const Vector2f& pos)
{
	SpriteObj::SetPos(pos);
	grass.setPosition(pos);
}

void Building::Draw(RenderWindow& window)
{
	SpriteObj::Draw(window);
	window.draw(grass);
}
