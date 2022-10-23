#include "StartPhaseUI.h"
#include "../../Scene/Info/Tile.h"
#include "../../Manager/ResourceMgr.h"

StartPhaseUI::StartPhaseUI()
{
}

StartPhaseUI::~StartPhaseUI()
{
}

void StartPhaseUI::Draw(RenderWindow& window)
{
	ChangeTex();
	SpriteObj::Draw(window);
}

void StartPhaseUI::ChangeTex()
{
	switch (Tile::GetMechCount() + 1)
	{
	case 0:
		sprite.setTexture(*RESOURCE_MGR->GetTexture("graphics/ui/startphase/dropriftwalkers/dropcombat.png"));	
		sprite.setTextureRect({ 0, 0, 356, 133 });
		break;
	case 1:
		sprite.setTexture(*RESOURCE_MGR->GetTexture("graphics/ui/startphase/dropriftwalkers/droptank.png"));		
		sprite.setTextureRect({ 0, 0, 356, 133 });
		break;
	case 2:
		sprite.setTexture(*RESOURCE_MGR->GetTexture("graphics/ui/startphase/dropriftwalkers/dropartil.png"));		
		sprite.setTextureRect({ 0, 0, 356, 80 });
		break;
	}
}
