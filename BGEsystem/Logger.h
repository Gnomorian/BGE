#ifndef BGE_LOGGER_H
#define BGE_LOGGER_H

#include "build.h"
#include <string>
#include <ctime>
#include "File.h"

#define LOGMSG(level, message, ...) Log(__LINE__, __FUNCTION__, __FILE__, level, message, __VA_ARGS__)
#define LOG_ERROR(message, ...) LOGMSG(BGE::System::ILogger::Level::LEVEL_ERROR, message, __VA_ARGS)
#define LOG_ERROR(message, ...) LOGMSG(BGE::System::ILogger::Level::LEVEL_DEBUG, message, __VA_ARGS)
#define LOG_ERROR(message, ...) LOGMSG(BGE::System::ILogger::Level::LEVEL_WARNING, message, __VA_ARGS)

namespace BGE
{
	namespace System
	{
		class ILogger
		{
		protected:
			char* fileName;
			File* logFile;
		public:
			enum Level
			{
				LEVEL_DEBUG,
				LEVEL_WARNING,
				LEVEL_ERROR
			};
			ILogger() { fileName = nullptr; }
			~ILogger() { delete fileName; delete logFile; };
			virtual void Info(const char* message) = 0;
			virtual void Log(int line, const char* function, const char* file, Level level, const char* message, ...) = 0;
			virtual void InitFile(const char* name) = 0;
			virtual bool ShowConsole(bool show) = 0;
		};

#ifdef BGE_WINDOWS
#define Logger BGE::System::WindowsLogger
		class WindowsLogger : public ILogger
		{
		public:
			WindowsLogger(bool showConsole = false);
			WindowsLogger(const char* fileName, bool showConsole = false);
			~WindowsLogger();
			void Info(const char* message) override;
			void Log(int line, const char* function, const char* file, Level level, const char* message, ...) override;
			void InitFile(const char* fileName) override;
			bool ShowConsole(bool show) override;
		};

#else
#endif // BGE_WINDOWS
	}
}
#endif // !LOGGER_H

