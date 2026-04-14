#pragma once
#include "Grid.h"
#include "Blocks.cpp"

class Game {
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void moveBlockLeft();
	void moveBlockRight();
	void moveBlockDown();
	Grid grid;

private:
	bool IsBlockOutside();
	void RotateBlock();
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;

};