#include "FillStartPos.h"

FillStartPos::FillStartPos()
{	
	SetTexture(*RESOURCE_MGR->GetTexture("graphics/ui/setmechpos.png"));
}

void FillStartPos::Init()
{
	SpriteObj::Init();
	isSpace = true;
}

void FillStartPos::Update(float dt)
{

}

void FillStartPos::Draw(RenderWindow& window)
{
	if (!isSpace)
		return;
	SpriteObj::Draw(window);
}
