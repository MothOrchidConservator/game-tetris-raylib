#include "Game.h"
#include <iostream>

Game::Game() {
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock() {
	if (blocks.empty()) {
		blocks = GetAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;

}

std::vector<Block> Game::GetAllBlocks() {
	return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::Draw() {
	grid.Draw();
	currentBlock.Draw();
}

void Game::HandleInput(){
	int keyPressed = GetKeyPressed();
	switch (keyPressed)
	{
	case KEY_LEFT:
		moveBlockLeft();
		break;
	case KEY_RIGHT:
		moveBlockRight();
		break;
	case KEY_DOWN:
		moveBlockDown();
		break;
	case KEY_UP:
		RotateBlock();
		break;
	default:
		break;
	}
}

void Game::moveBlockLeft() {
	currentBlock.Move(0, -1);
	if (IsBlockOutside()) {
		currentBlock.Move(0, 1);
	}
}

void Game::moveBlockRight() {
	currentBlock.Move(0, 1);
	if (IsBlockOutside()) {
		currentBlock.Move(0, -1);
	}
}

void Game::moveBlockDown() {
	currentBlock.Move(1, 0);
	if (IsBlockOutside()) {
		currentBlock.Move(-1, 0);
	}
}

bool Game::IsBlockOutside()
{
	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles) {
		if (grid.IsCellOutside(item.row, item.column)) {
			return true;
		}
	}
	return false;
}

void Game::RotateBlock() {
	currentBlock.Rotate();
	if (IsBlockOutside()) {
		currentBlock.UndoRotation();
	}
}