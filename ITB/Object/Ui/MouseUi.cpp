#include "MouseUi.h"
#include "../../Manager/ResourceMgr.h"
#include "../../Manager/InputMgr.h"

MouseUi::MouseUi()
{		
	sprite.setTexture(*RESOURCE_MGR->GetTexture("graphics/ui/mouse/pointer.png"));
}

MouseUi::~MouseUi()
{
}

void MouseUi::Update(float dt)
{
	SetPos(InputMgr::GetMousePos());
}
