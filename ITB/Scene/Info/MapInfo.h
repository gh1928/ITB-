#pragma once
#include "../../Framework/EnumClasses.h"
#include <array>
#include "Tile.h"

//추후에 파일 입출력방식으로 변경

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

