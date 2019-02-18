#include "INIFile.h"

BGE::Engine::
INIFile::INIFile()
{
	file = new File;
}

BGE::Engine::
INIFile::INIFile(const char* fileName, int length)
{
	file = new File;
	file->SetFilename(fileName, length);
}

BGE::Engine::
INIFile::~INIFile()
{
	delete file;
}

const char* BGE::Engine::
INIFile::GetIniFilename()
{
	return nullptr;
}

const char* BGE::Engine::
INIFile::GetWorkingDirectory()
{
	return nullptr;
}

int BGE::Engine::
INIFile::GetInt(const char* category, const char* setting, int defaultValue)
{
	return 0;
}

const char* BGE::Engine::
INIFile::GetString(const char* category, const char* setting, const char* defaultValue)
{
	return nullptr;
}

int BGE::Engine::
INIFile::GetBool(const char* category, const char* setting, bool defaultValue)
{
	return 0;
}

void BGE::Engine::
INIFile::ParseInifile()
{

}

void BGE::Engine::
INIFile::FlushInifile()
{

}
