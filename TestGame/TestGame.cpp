#include "modapi.h"
#include "Game.h"

BGE::System::IGame* LoadBGEMod()
{
	return new Game;
}