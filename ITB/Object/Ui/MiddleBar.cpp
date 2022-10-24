#include "MiddleBar.h"
#include "../../Manager/ResourceMgr.h"
#include "../../Framework/Utils.h"

MiddleBar::MiddleBar(GamePhase& phase)
	:phase(phase)
{
	SetTexture(*RESOURCE_MGR->GetTexture("graphics/ui/bar_date.png"));
	Utils::SetOrigin(sprite, Origins::MC);	
}

void MiddleBar::Update(float dt)
{
	if (phase != GamePhase::Player)
		return;
}

void MiddleBar::Draw(RenderWindow& window)
{
	if (phase != GamePhase::Player)
		return;

	SpriteObj::Draw(window);
}
