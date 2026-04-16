#pragma once
#include "Grid.h"
#include "Blocks.cpp"

class Game {
public:
	Game();
	~Game();
	void Draw();
	void HandleInput();
	void moveBlockDown();
	bool gameOver;
	int score;
	Music music;

private:
	Grid grid;
	void moveBlockLeft();
	void moveBlockRight();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int  lineCleared, int moveDownPoints );
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
	Sound rotateSound;
	Sound clearSound;
};