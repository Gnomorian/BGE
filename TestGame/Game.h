#pragma once
#include "BGEsystem/Mod.h"
class Game : public BGE::System::IGame
{
public:
	Game();
	~Game();
	void Update() override;
	void Draw() override;
	const char* GetVersion() override;
	const char* GetName() override;
	const char* GetDescription() override;
	int GetPriority() override;
};

