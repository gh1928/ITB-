#pragma once

enum class Origins
{
	TL,	// 0
	TC,
	TR,
	ML,
	MC,
	MR,
	BL,
	BC,
	BR,	// 8
};

enum class Scenes
{
	None = -1,
	DevScene,
	DevScene2,
};

enum class TileTypes
{
	None = -1,
	Stand = 0,
	Water,
	Mountain,
	Building1,
	Building2,
	Rail,
};

enum class Squd
{
	None = -1,
	RiftWalkers,
};

enum class MechClass
{
	None = -1,
	Prime,
	Brute,
	Range,
};

enum class GamePhase
{
	None = -1,
	Start,
	Deploy,
	Playing,
	End,
};

enum class AnimationType
{
	None = -1,
	Projectile,
	Actor,	
	Background,
};