#pragma once
#include <vector>
#include <map>
#include "position.h"

class Block {
public:
	Block();
	int id;

private:
	int cellSize;
	int rotationState;

};