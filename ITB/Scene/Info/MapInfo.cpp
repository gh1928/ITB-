#include "MapInfo.h"
#include <vector>
#include <fstream>
#include "../../Scene/Scene.h"

MapInfo::MapInfo()
{
}

MapInfo::~MapInfo()
{
}

void MapInfo::Init(Scene* scene, GamePhase* phase)
{
	phaseTimer = 0.f;

	this->scene = scene;
	this->phase = phase;

	squad[0] = new CombatMech(*this->phase);
	squad[1] = new CannonMech(*this->phase);
	squad[2] = new ArtilleryMech(*this->phase);

	ifstream is("stage/stage01.txt");
	char number;

	for (int i = 0; i < 8; ++i)
	{		
		for (int j = 0; j < 8; ++j)
		{			
			is >> number;

			mapInfo[i][j].SetType((TileTypes)atoi(&number));
			mapInfo[i][j].Init(this->scene, this);
		}
	}	
}

bool MapInfo::TileSpace(int idx1, int idx2)
{
	if (idx1 < 0 || 7 < idx1)
		return false;
	if (idx2 < 0 || 7 < idx2)
		return false;


	return mapInfo[idx1][idx2].IsSpace();	
}

void MapInfo::Update(float dt)
{
	phaseTimer -= dt;

	StartPhaseUpdate(dt);
	DeployPhaseUpdate(dt);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			mapInfo[i][j].Update(dt);
		}
	}
}

void MapInfo::StartPhaseUpdate(float dt)
{
	if (*phase != GamePhase::Start)
		return;	
}

void MapInfo::DeployPhaseUpdate(float dt)
{
	if (*phase != GamePhase::Deploy)
		return;

	if (phaseTimer > 0.f)
		return;

	if (squad[1]->GetActive())
		squad[2]->SetActive(true);

	if (squad[0]->GetActive())
		squad[1]->SetActive(true);

	squad[0]->SetActive(true);

	phaseTimer = 0.4f;

	for (auto i : squad)
	{
		if (!i->GetActive())
			return;
	}	
}
