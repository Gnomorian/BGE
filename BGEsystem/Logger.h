#ifndef BGE_LOGGER_H
#define BGE_LOGGER_H

#include "build.h"
#include "FileSystem.h"

namespace BGE
{
	namespace System
	{
		class ILogger
		{
		public:
			ILogger();
			~ILogger();
			void Info(const char* message);
			void Log(const char* message);
		};

#ifdef BGE_WINDOWS
#define Logger BGE::System::Logger
		class WindowsLogger
		{
			WindowsLogger();
			~WindowsLogger();
		};

#else
#endif // BGE_WINDOWS
	}
}
#endif // !LOGGER_H

