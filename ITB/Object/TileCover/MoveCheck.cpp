#include "MoveCheck.h"

MoveCheck::MoveCheck()
{
	SetTexture(*RESOURCE_MGR->GetTexture("graphics/ui/movecheck.png"));
	enabled = false;
}
