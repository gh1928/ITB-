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
	DevScene,
};

enum class TileTypes
{
	None = -1,
	Stand,
	Rail,
	Water,
};

enum class Squd
{
	RiftWalkers,
};

enum class MechClass
{
	Prime,
	Brute,
	Range,
};