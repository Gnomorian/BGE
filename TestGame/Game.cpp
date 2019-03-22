#include "Game.h"



Game::Game()
{
	running = true;
	counter = 0;
}


Game::~Game()
{
}

void Game::Update()
{
	// update game logic
	if (++counter >= 10)
		running = false;
}

void Game::Draw()
{
	// draw stuff to the screen
}

const char* Game::GetVersion()
{
	// returns the version number of this mod
	return "0.0.1";
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

bool Game::IsRunning()
{
	return running;
}

void Game::Cleanup()
{
	MessageBox(nullptr, "I have run 10 times, now im cleaning up!", "DONE", MB_OK);
}