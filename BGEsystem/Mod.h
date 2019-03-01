#ifndef BGE_MOD_H
#define BGE_MOD_H

#include "build.h"

namespace BGE
{
	namespace System
	{
		class EXPORT IMod
		{
		public:
			virtual void Update() = 0;
			virtual void Draw() = 0;
			virtual const char* GetVersion() = 0;
			virtual const char* GetName() = 0;
			virtual const char* GetDescription() = 0;
			virtual int GetPriority() = 0;
		};

		class IGame : public IMod
		{

		};
	}
}

#endif // BGE_MOD_H
