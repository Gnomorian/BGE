#include "INIFile.h"

INIFile::INIFile()
{
	inifile = new File;
}

INIFile::INIFile(const char* fileName, int length)
{
	inifile = new File;
	inifile->SetFilename(fileName, length);
}

INIFile::~INIFile()
{
	delete inifile;
}