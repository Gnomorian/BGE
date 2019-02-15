#include "AlienLib.h"
#include "Exception.h"

BGE::System::
WindowsAlienLib::WindowsAlienLib(const char* name)
{
	SetFilename(name);
}

BGE::System::
WindowsAlienLib::WindowsAlienLib()
{
	handle = nullptr;
}

BGE::System::
WindowsAlienLib::~WindowsAlienLib()
{
	if(handle)
		FreeLibrary(handle);
	if (fileName)
		delete fileName;
}

void BGE::System::
WindowsAlienLib::SetFilename(const char* name)
{
	if (fileName)
		return; // throw exception, already initialized.
	size_t length = strlen(name);
	SetFilename(name, length);
}

void BGE::System::
WindowsAlienLib::SetFilename(const char* name, size_t length)
{
	fileName = new char[length + 1];
	memcpy(fileName, name, length);
	fileName[length] = 0;
}

const char* BGE::System::
WindowsAlienLib::GetFilename()
{
	return fileName;
}

void* BGE::System::
WindowsAlienLib::GetFunction(const char* funcName)
{
	void* funcPtr = GetProcAddress(handle, funcName);
	if(funcPtr == nullptr)
		throw BGEexception("Failed to get function from forign library.", __LINE__, __FUNCTION__, __FILE__);
	return funcPtr;
}

bool BGE::System::
WindowsAlienLib::Load()
{
	handle = LoadLibrary(fileName);
	if (handle == nullptr)
		throw BGEexception("Failed to load forign library.", __LINE__, __FUNCTION__, __FILE__);
}

bool BGE::System::
WindowsAlienLib::Unload()
{
	if(FreeLibrary(handle) == false)
		throw BGEexception("Failed to unload forign library.", __LINE__, __FUNCTION__, __FILE__);
	handle = nullptr;
}
