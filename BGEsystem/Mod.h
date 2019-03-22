#ifndef BGE_MOD_H
#define BGE_MOD_H

#include "build.h"

namespace BGE
{
	namespace System
	{
		class EXPORT IMod
		{
		protected:
			//TODO: handles too singletons that interface with graphics, audio, network, system
		public:
			virtual void Update() = 0;
			virtual void Draw() = 0;
			virtual const char* GetVersion() = 0;
			virtual const char* GetName() = 0;
			virtual const char* GetDescription() = 0;
			virtual int GetPriority() = 0;
			virtual void Cleanup() = 0;
		};

		class IGame : public IMod
		{
		public:
			virtual bool IsRunning() = 0;
		};
	}
}

#endif // BGE_MOD_H
