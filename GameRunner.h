#ifndef BGE_GAME_RUNNER
#define BGE_GAME_RUNNER

#include "INIFile.h"
#include "BGEsystem/AlienLib.h"

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
			void Run();
			bool Initialize();
		private:
			INIFile inifile;
			AlienLib game;
		};
	}
}

#endif // !BGE_GAME_RUNNER