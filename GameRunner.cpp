#include "GameRunner.h"
#include "modapi.h"

BGE::Engine::
GameRunner::GameRunner() : inifile("..\\BGE.ini", 10)
{
	const char* gamename = inifile.GetString("mods", "game", nullptr);
	if (gamename != nullptr)
	{
		game.SetFilename(gamename);
		if (game.Load() && Initialize())
		{
			Run();
		}
	}
}

BGE::Engine::
GameRunner::~GameRunner()
{
}

void BGE::Engine::
GameRunner::Run()
{
	WriteStuff stuff = (WriteStuff)game.GetFunction("WriteStuff");
	(stuff)();
}

bool BGE::Engine::
GameRunner::Initialize()
{
	return false;
}