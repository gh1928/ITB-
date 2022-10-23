#pragma once
#include "../Framework/EnumClasses.h"
#include "../Framework/Framework.h"
#include <list>

using namespace std;

class Object;
class Scene
{
protected:
	Scenes type;	

public:
	Scene(Scenes type);
	virtual ~Scene();

	virtual void Init() = 0;
	virtual void Release();

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);

	Texture* GetTexture(const string& id);
};

