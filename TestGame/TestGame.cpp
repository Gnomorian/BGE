#include "modapi.h"
#include "Game.h"

BGE::System::IGame* AlienGetGame()
{
	return new Game;
}