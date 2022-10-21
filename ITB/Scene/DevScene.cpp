#include "DevScene.h"
#include "../Manager/ResourceMgr.h"
#include "../Framework/Utils.h"

DevScene::DevScene()
	:Scene(Scenes::DevScene)
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	mapInfo.Init();

	MakeBackground();	

	Vector2u texSize = RESOURCE_MGR->GetTexture("graphics/tiles/ground_0.png")->getSize();
	Vector2f startPos = { WINDOW_WIDTH * 0.5f - texSize.x , WINDOW_HEIGHT * 0.05f };

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{	
			SetTileTex(i, j);
			drawMap[i][j]->SetPos({ 56.f * (j - i) , 42.f * (j + i)});
			drawMap[i][j]->SetPos(drawMap[i][j]->GetPos() + startPos);
			
			mapInfo.GetTilesInfo(i, j).SetPos(drawMap[i][j]->GetPos());

			drawObject[i][j] = mapInfo.GetTilesInfo(i, j).GetObjList();
		}
	}
}

void DevScene::Release()
{
}

void DevScene::Enter()
{
}

void DevScene::Exit()
{
}

void DevScene::Update(float dt)
{
	mapInfo.Update(dt);
	UpdateStartPhase(dt);
}

void DevScene::Draw(RenderWindow& window)
{
	for (int i = 0; i < backGround.size(); ++i)
	{
		window.draw(backGround[i]);
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			drawMap[i][j]->Draw(window);
		}
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			for (auto obj : *drawObject[i][j])
			{
				if (obj != nullptr && obj->GetActive())
					obj->Draw(window);
			}
		}
	}
}

void DevScene::MakeBackground()
{
	Vector2u size = RESOURCE_MGR->GetTexture("graphics/background/bg.png")->getSize();

	for (int i = 0; i < backGround.size() - 1; ++i)
	{
		backGround[i].setTexture(*RESOURCE_MGR->GetTexture("graphics/background/bg.png"));
		backGround[i].setPosition({ (float)size.x * (i % 9), (float)size.y * (i / 9) });
	}	
	backGround.back().setTexture(*RESOURCE_MGR->GetTexture("graphics/background/map_shadow.png"));
	backGround.back().setScale(2, 2);
	Utils::SetOrigin(backGround.back(), Origins::TC);
	backGround.back().setPosition({ WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.17f });
}

void DevScene::SetTileTex(int i, int j)
{
	drawMap[i][j] = new SpriteObj;
	switch (mapInfo.GetTilesInfo(i, j).GetType())
	{
	case TileTypes::Stand:
		drawMap[i][j]->SetTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/ground_0.png"));
		break;
	case TileTypes::Rail:
		drawMap[i][j]->SetTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/ground_rail.png"));
		break;
	case TileTypes::Water:
		drawMap[i][j]->SetTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/water_0.png"));
		break;
	}
}

void DevScene::UpdateStartPhase(float dt)
{
}
