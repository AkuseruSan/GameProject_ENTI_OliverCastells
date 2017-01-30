#pragma once

#define MAP_VALUE(v, inMin, inMax, outMin, outMax) ((v - inMin) / (inMax - inMin)) * (outMax - outMin) + outMin

struct Vector
{
	int x;
	int y;
};