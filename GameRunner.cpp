#include "GameRunner.h"
#include "modapi.h"

BGE::Engine::
GameRunner::GameRunner() : inifile("..\\BGE.ini", 10)
{
	const char* gamename = inifile.GetString("mods", "game", nullptr);
	if (gamename != nullptr)
	{
		gamedll.SetFilename(gamename);
		if (gamedll.Load() && Initialize())
		{
			Run();
		}
	}
}

BGE::Engine::
GameRunner::~GameRunner()
{
}

bool BGE::Engine::
GameRunner::Run()
{
	if (Initialize())
	{
		// find if this dll is a mod or the game.
		AlienGetGame gameclass = (AlienGetGame)gamedll.GetFunction("GetGame");
		System::IGame* gam = (gameclass)();
		AlienGetMod modclass = (AlienGetMod)gamedll.GetFunction("GetMod");
		System::IMod* mod = (modclass)();

		if(gam)
		{
			if (mod)
			{
				printf("%s has a mod and game implementation, this is invalid.\n", gamedll.GetFilename());
				return false;
			}
			while(true)
			{
				gam->Update();
				gam->Draw();
			}
		}
		else
		{
			if (gam)
			{
				printf("%s has a mod and game implementation, this is invalid.\n", gamedll.GetFilename());
				return false;
			}
			// add too the list of mods in priority queue
		}
	}
	else
	{
		return false;
	}
	
}

bool BGE::Engine::
GameRunner::Initialize()
{
	return gamedll.Load();
}