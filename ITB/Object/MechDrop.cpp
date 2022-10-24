#include "MechDrop.h"
#include "../Manager/ResourceMgr.h"
#include "../Scene/Info/Tile.h"

MechDrop::MechDrop(bool mechDroppable)
	:mechDroppable(mechDroppable)
{
	SetSprites();

	switch (Tile::GetMechCount() + 1)
	{
	case 0:
		SetTex(&mech, "graphics/mech/combat/mech_punch_ns.png");
		SetTex(&mechOutline, "graphics/mech/combat/mech_punch_line.png");
		break;
	case 1:
		SetTex(&mech, "graphics/mech/cannon/mech_tank_ns.png");
		SetTex(&mechOutline, "graphics/mech/cannon/mech_tank_line.png");
		break;
	case 2:
		SetTex(&mech, "graphics/mech/artillery/mech_artillery_ns.png");
		SetTex(&mechOutline, "graphics/mech/artillery/mech_artillery_line.png");
		break;
	}

	arrowPoseFix = { 30.f, -24.f };
	xMarkPoseFix = { 33.f, 20.f };
	mechPoseFix = { 20.f, -45.f };
}

MechDrop::~MechDrop()
{
}

void MechDrop::SetPos(const Vector2f& pos)
{
	deployArrow.setPosition(pos + arrowPoseFix);
	deployXmark.setPosition(pos + xMarkPoseFix);

	mech.setPosition(pos + mechPoseFix);
	mechOutline.setPosition(pos + mechPoseFix);
}

void MechDrop::Draw(RenderWindow& window)
{
	mechDroppable ? window.draw(deployArrow) : window.draw(deployXmark);
	
	mechOutline.setColor(Color(255, mechDroppable ? 255 : 0, 0));
	window.draw(mechOutline);
	window.draw(mech);
}

void MechDrop::SetTex(Sprite* sprite, String id)
{
	sprite->setTexture(*RESOURCE_MGR->GetTexture(id));
	sprite->setScale(2, 2);
}

void MechDrop::SetSprites()
{
	if (Tile::GetMechCount() >= 2)
		return;

	SetTex(&deployArrow, "graphics/ui/startphase/deployment_arrow.png");
	deployArrow.setColor(Color(255, 255, 0));

	SetTex(&deployXmark, "graphics/ui/startphase/deployment_x.png");
	deployXmark.setColor(Color(255, 0, 0));
}

