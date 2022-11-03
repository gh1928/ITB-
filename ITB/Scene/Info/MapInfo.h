#pragma once
#include "../../Framework/EnumClasses.h"
#include <array>
#include <list>
#include "Tile.h"

using namespace std;

class Scene;

class MapInfo
{
protected:	
	array<array<Tile, 8>, 8> mapInfo;	
	Scene* scene;

	array<Mech*, 3> squad;
	GamePhase* phase;

	Vector2i prevCursorPos;
	Vector2i currCursorPos;

	list<Vector2i> path;

	bool chekingObject;
	bool resetNodes;
	float phaseTimer;
public:
	MapInfo();
	~MapInfo();

	void Init(Scene* scene, GamePhase* phase);
	Tile& GetTilesInfo(int idx1, int idx2) { return mapInfo[idx1][idx2]; }
	
	bool TileSpace(int idx1, int idx2);

	void Update(float dt);
	void StartPhaseUpdate(float dt);
	void DeployPhaseUpdate(float dt);
	void PlayerPhaseUpdate(float dt);
	void MovePhaseUpdate(float dt);

	bool IsCursorMoved();

	GamePhase* GetPhase() { return phase; }
	Mech* GetSqud(int index) { return squad[index]; }
	
	list<Vector2i>* GetPathList() { return &path; }

	bool* GetChekingObject() { return &chekingObject; }
};

