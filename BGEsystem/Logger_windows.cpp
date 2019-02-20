#include "Logger.h"

BGE::System::
WindowsLogger::WindowsLogger(bool showConsole)
{
	ShowConsole(showConsole);
}

BGE::System::
WindowsLogger::WindowsLogger(const char* fileName, bool showConsole)
{
	ShowConsole(showConsole);
	InitFile(fileName);
}

BGE::System::
WindowsLogger::~WindowsLogger()
{

}

void BGE::System::
WindowsLogger::Info(const char* message)
{

}

void BGE::System::
WindowsLogger::Log(int line, const char* function, const char* file, Level level, const char* message, ...)
{
	std::string buffer;
	switch (level)
	{
		case Level::LEVEL_DEBUG:
			buffer += "[DEBUG] ";
			break;
		case Level::LEVEL_ERROR:
			buffer += "[ERROR] ";
			break;
		case Level::LEVEL_WARNING:
			buffer += "[WARNING] ";
			break;
	};
	buffer += message;
	va_list va;
	va_start(va, 3);
	printf(buffer.c_str(), va);
	va_end(va);
}

void BGE::System::
WindowsLogger::InitFile(const char* name)
{
	size_t len = strlen(fileName);
	fileName = new char[len + 1];
	memcpy(fileName, name, len * sizeof(char));
	fileName[len] = NULL;

	logFile = new File;
	logFile->SetFilename(fileName, len);
	logFile->SetMode(BGE::System::IFile::Mode::BGE_F_WRITE);
}

bool BGE::System::
WindowsLogger::ShowConsole(bool show)
{
	if (show)
	{
		AllocConsole();
	}
	else
	{
		FreeConsole();
	}
	return true;
}
