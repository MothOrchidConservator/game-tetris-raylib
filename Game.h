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
	bool gameOver;
	int score;

private:
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int  lineCleared, int moveDownPoints );
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;

};