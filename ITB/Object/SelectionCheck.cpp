#include "SelectionCheck.h"
#include "../Manager/InputMgr.h"

SelectionCheck::SelectionCheck(bool& isCursor)
	:isCursor(isCursor)
{
	SetTexture(*RESOURCE_MGR->GetTexture("graphics/ui/tilesel.png"));
	localCenterPos = Vector2f{ 56.f, 42.f };	
}

void SelectionCheck::Update(float dt)
{
	Vector2f mousePos = InputMgr::GetMousePos();
	mousePos -= position;

	isCursor = (abs(localCenterPos.x - mousePos.x) / localCenterPos.x + abs(localCenterPos.y - mousePos.y) / localCenterPos.y) < 1.f ?
		true : false;
}

void SelectionCheck::Draw(RenderWindow& window)
{
	if (isCursor)
		window.draw(sprite);
}
