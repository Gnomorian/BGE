#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::Update()
{
	// update game logic
}

void Game::Draw()
{
	// draw stuff to the screen
}

const char* Game::GetVersion()
{
	// returns the version number of this mod
}

const char* Game::GetName()
{
	// returns the name of this mod
	return "Amazballs Game";
}

const char* Game::GetDescription()
{
	// returns a description of this mod
	return "A Demo game";
}

int Game::GetPriority()
{
	// returns the priority of this mod
	// this is ignored for game
	return 1;
}
