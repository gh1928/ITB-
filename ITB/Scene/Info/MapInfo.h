#pragma once
#include "../../Framework/EnumClasses.h"
#include <array>
#include "Tile.h"

//���Ŀ� ���� ����¹������ ����

using namespace std;

class MapInfo
{
protected:	
	array<array<Tile, 8>, 8> mapInfo;	
public:
	MapInfo();
	~MapInfo();

	void Init();
	Tile GetTilesInfo(int idx1, int idx2) { return mapInfo[idx1][idx2]; }

	void Update(float dt);
};

