#pragma once
#include "../../Framework/EnumClasses.h"
#include <array>
#include "Tile.h"

//���Ŀ� ���� ����¹������ ����

using namespace std;

class Scene;
class MapInfo
{
protected:	
	array<array<Tile, 8>, 8> mapInfo;	
	Scene* scene;

	GamePhase* phase;
public:
	MapInfo();
	~MapInfo();

	void Init(Scene* scene, GamePhase* phase);
	Tile& GetTilesInfo(int idx1, int idx2) { return mapInfo[idx1][idx2]; }

	void Update(float dt);
};

