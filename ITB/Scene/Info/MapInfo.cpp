#include "MapInfo.h"
#include <vector>
#include <fstream>

MapInfo::MapInfo()
{
}

MapInfo::~MapInfo()
{
}

void MapInfo::Init()
{
	ifstream is("stage/stage01.txt");
	char number;

	for (int i = 0; i < 8; ++i)
	{		
		for (int j = 0; j < 8; ++j)
		{			
			is >> number;

			mapInfo[i][j].Init();			
			mapInfo[i][j].SetType((TileTypes)atoi(&number));
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
