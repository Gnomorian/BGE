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
	return file->GetFilename();
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
	//TODO: implement this properly, for now hack it so i can do more interesting things
	return "C:\\Users\\cnwwc5\\Documents\\BGE\\Build\\Debug\\Data\\Bin\\TestGame.dll";
}

int BGE::Engine::
INIFile::GetBool(const char* category, const char* setting, bool defaultValue)
{
	return 0;
}

inline void GetCategoryName(char* character, char* categoryName[])
{
	if(*character == '[')
		character++;
	int length = 0;
	for(char* chr = character; *chr != ']'; chr++)
		length++;
	char* result = (char*)realloc(*categoryName, length + 1);
	result[length] = 0;
	if (result)
		*categoryName = result;
}

void BGE::Engine::
INIFile::ParseInifile()
{
	char* currentCategoryName = nullptr;
	const char* content = file->ReadString();
	for(char* character = (char*)content; character; character++)
	{
		if(*character == '[')
		{
			GetCategoryName(character, &currentCategoryName);
			character++;
		}
		else
		{
			// get the settings within this category
		}
	}
}

void BGE::Engine::
INIFile::FlushInifile()
{

}
