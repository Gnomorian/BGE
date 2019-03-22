#pragma once
#include <Windows.h>
#include "BGEsystem/Mod.h"
class Game : public BGE::System::IGame
{
private:
	bool running;
	int counter;
public:
	Game();
	~Game();
	void Update() override;
	void Draw() override;
	const char* GetVersion() override;
	const char* GetName() override;
	const char* GetDescription() override;
	bool IsRunning() override;
	int GetPriority() override;
	void Cleanup() override;
};

