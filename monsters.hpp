#pragma once

#include "geometric.hpp"
#include <string>
#include <cstring>
#include <cstdlib>

class Monster{
public:
	std::string name; // Default "Larry"
	Point location; // Random location on mp
	unsigned hp; // Hit points (25)
	unsigned ap; // Attack power (10)

public:
	Monster();
	void move(char map[][80]);

};
