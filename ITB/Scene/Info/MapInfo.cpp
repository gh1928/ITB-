#include "MapInfo.h"

MapInfo::MapInfo()
{
}

MapInfo::~MapInfo()
{
}

void MapInfo::Init()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			mapInfo[i][j].Init();
			mapInfo[i][j].SetType(TileTypes::Stand);	
		}
	}
}

void MapInfo::Update(float dt)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			mapInfo[i][j].Update(dt);
		}
	}
}
