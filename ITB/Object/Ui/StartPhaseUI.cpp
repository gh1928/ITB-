#include "StartPhaseUI.h"
#include "../../Scene/Info/Tile.h"
#include "../../Manager/ResourceMgr.h"
#include "../../Manager/InputMgr.h"

StartPhaseUI::StartPhaseUI(GamePhase& phase)
	:phase(phase)
{	
	checkBox = { 15,105,185,60 };		
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
	case 3:		
		sprite.setTexture(
			checkBox.contains((Vector2i)InputMgr::GetMousePos()) ? 
			*RESOURCE_MGR->GetTexture("graphics/ui/startphase/dropendcheck.png"): 
			*RESOURCE_MGR->GetTexture("graphics/ui/startphase/dropend.png"));
		sprite.setTextureRect({ 0, 0, 300, 155 });
	}
}

void StartPhaseUI::PhaseEnd()
{
	if ((Tile::GetMechCount() >= 2)
		&& checkBox.contains((Vector2i)InputMgr::GetMousePos())
		&& InputMgr::GetMouseButtonDown(Mouse::Left))
	{
		phase = GamePhase::Deploy;
		enabled = false;
	}		
}

void StartPhaseUI::Update(float dt)
{
	PhaseEnd();
}
