#include "Mountain.h"
#include "../../Manager/ResourceMgr.h"

Mountain::Mountain()
{
	SetTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/mountain_0.png"));
	sprite.setOrigin({ 0, 22.f });
}

Mountain::~Mountain()
{
}

void Mountain::SetBrokenTex()
{
	SetTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/mountain_0_broken.png"));
}
