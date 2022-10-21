#include "DevScene.h"
#include "../Manager/ResourceMgr.h"

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
	Vector2u texSize = RESOURCE_MGR->GetTexture("graphics/tiles/ground_0.png")->getSize();	
	Vector2f startPos = { WINDOW_WIDTH * 0.5f - texSize.x , WINDOW_HEIGHT * 0.05f };
	
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
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
			drawMap[i][j]->SetPos({ 56.f * (j - i) , 42.f * (j + i)});
			drawMap[i][j]->SetPos(drawMap[i][j]->GetPos() + startPos);

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
}

void DevScene::Draw(RenderWindow& window)
{
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
				if (obj != nullptr)
					obj->Draw(window);
			}
		}
	}
}
