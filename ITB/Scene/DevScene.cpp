#include "DevScene.h"
#include "../Manager/ResourceMgr.h"
#include "../Framework/Utils.h"
#include "../Object/InteractiveObject.h"
#include "../Object/TileCover/Water.h"


DevScene::DevScene()
	:Scene(Scenes::DevScene), uiULpos({15,10})
{
	
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	FRAMEWORK->GetWindow().setMouseCursorVisible(false);
	phase = GamePhase::Start;
	mapInfo.Init(this, &phase);

	MakeBackground();	

	Vector2u texSize = RESOURCE_MGR->GetTexture("graphics/tiles/ground_0.png")->getSize();
	Vector2f startPos = { WINDOW_WIDTH * 0.5f - texSize.x , WINDOW_HEIGHT * 0.05f };

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{	
			SetTileTex(i, j);
			for (auto map : drawMap[i][j])
			{
				Vector2f pos = { 56.f * (j - i) , 42.f * (j + i) };
				map->SetPos(pos + startPos);
			}
						
			mapInfo.GetTilesInfo(i, j).SetPos(drawMap[i][j].front()->GetPos());

			objs[i][j] = mapInfo.GetTilesInfo(i, j).GetObjList();
			actObjs[i][j] = mapInfo.GetTilesInfo(i, j).GetActObjList();
			uiObjs[i][j] = mapInfo.GetTilesInfo(i, j).GetUiObjList();
		}
	}

	
	sceneUi.push_back(new StartPhaseUI(phase));
	sceneUi.back()->SetPos(uiULpos);
	sceneUi.push_back(new MouseUi);
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

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (mapInfo.GetTilesInfo(i, j).GetType() == TileTypes::Water)
			{
				for (auto map : drawMap[i][j])
				{
					map->Update(dt);
				}
			}
		}
	}

	for (auto ui : sceneUi)
	{
		ui->Update(dt);
	}	

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
			for (auto map : drawMap[i][j])
			{
				map->Draw(window);
			}			
		}
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			for (auto obj : *objs[i][j])
			{
				if (obj != nullptr && obj->GetActive())
					obj->Draw(window);
			}
			for (auto obj : *actObjs[i][j])
			{
				if (obj != nullptr && obj->GetActive())
					obj->Draw(window);
			}
			for (auto obj : *uiObjs[i][j])
			{
				if (obj != nullptr && obj->GetActive())
					obj->Draw(window);
			}
		}
	}

	for (auto ui : sceneUi)
	{
		ui->Draw(window);
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
	drawMap[i][j].push_back(new SpriteObj);
	switch (mapInfo.GetTilesInfo(i, j).GetType())
	{
	case TileTypes::Stand:
		drawMap[i][j].back()->SetTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/ground_0.png"));
		break;
	case TileTypes::Water:
		drawMap[i][j].back()->SetTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/water_0.png"));
		drawMap[i][j].push_back(new Water);		
		break;
	case TileTypes::Rail:
		drawMap[i][j].back()->SetTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/ground_rail.png"));
		break;
	default:
		drawMap[i][j].back()->SetTexture(*RESOURCE_MGR->GetTexture("graphics/tiles/ground_0.png"));
		break;
	}
}

void DevScene::InitStartPhase()
{
}

void DevScene::UpdateStartPhase(float dt)
{

}
