#include "GameRunner.h"
#include "modapi.h"

BGE::Engine::
GameRunner::GameRunner() : inifile("..\\BGE.ini", 10)
{
	initialized = false;
	const char* gamename = inifile.GetString("mods", "game", nullptr);
	if (gamename != nullptr)
	{
		gamedll.SetFilename(gamename);
	}
}

BGE::Engine::
GameRunner::~GameRunner()
{
}

bool BGE::Engine::
GameRunner::Run()
{
	Initialize();
	if (initialized)
	{
		// get the interface for all the loaded mods in a priority queue
		LoadBGEMod getInterface = (LoadBGEMod)gamedll.GetFunction("LoadBGEMod");
		System::IGame* gam = (getInterface)();
		while (gam->IsRunning())
		{
			gam->Update();
		}
		gam->Cleanup();
	}
	else
	{
		return false;
	}
}

bool BGE::Engine::
GameRunner::Initialize()
{
	if (initialized)
		return true;
	return initialized = gamedll.Load();
}