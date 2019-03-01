#ifndef BGE_GAME_RUNNER
#define BGE_GAME_RUNNER

#include "INIFile.h"
#include "BGEsystem/AlienLib.h"
#include "BGEsystem/Mod.h"

namespace BGE
{
	namespace Engine
	{
		class INIFile;
		class GameRunner
		{
		public:
			GameRunner();
			~GameRunner();
			bool Run();
			bool Initialize();
		private:
			INIFile inifile;
			AlienLib gamedll;
			System::IMod* gameInterface;
		};
	}
}

#endif // !BGE_GAME_RUNNER