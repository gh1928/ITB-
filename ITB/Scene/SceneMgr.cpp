#include "SceneMgr.h"
#include "DevScene.h"
#include "DevScene2.h"
bool SceneMgr::Init()
{
    sceneMap[Scenes::DevScene] = new DevScene;
    sceneMap[Scenes::DevScene2] = new DevScene2;
    currScene = Scenes::DevScene;

    for (auto pair : sceneMap)
    {
        pair.second->Init();
    }

    sceneMap[currScene]->Enter();

    return true;
}

Scenes SceneMgr::GetCurrScene() const
{
    return currScene;//현재 씬의 종류
}

Scene* SceneMgr::GetScene(Scenes scene)
{
    return sceneMap[scene];// 현재 씬의 주소
}

void SceneMgr::ChangeScene(Scenes scene)
{
    sceneMap[currScene]->Exit();
    currScene = scene;
    sceneMap[currScene]->Enter();
}

void SceneMgr::Update(float dt)
{
    sceneMap[currScene]->Update(dt);
}

void SceneMgr::Draw(RenderWindow& window)
{
    sceneMap[currScene]->Draw(window);
}

