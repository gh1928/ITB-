#include "Scene.h"
#include "../Manager/ResourceMgr.h"
#include "../Framework/Framework.h"

Scene::Scene(Scenes type)
	: type(type)
{
}

Scene::~Scene()
{
	Release();

}

void Scene::Release()
{
}

void Scene::Update(float dt)
{

}

void Scene::Draw(RenderWindow& window)
{

}

Texture* Scene::GetTexture(const string& id)
{
	return RESOURCE_MGR->GetTexture(id);
}
