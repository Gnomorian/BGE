#include "File.h"
#include <assert.h>

BGE::System::
FileWindows::FileWindows()
{
	fileHandle = nullptr;
	mode = Mode::BGE_F_READ | Mode::BGE_F_WRITE;
	share = Share::BGE_F_SHARE_READ;
}

BGE::System::
FileWindows::~FileWindows()
{
	CloseHandle(fileHandle);
}

bool BGE::System::
FileWindows::Open()
{
	if (fileHandle != nullptr)
	{
		return false;
	}
	fileHandle = CreateFile(fileName, mode, share, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	return (bool)fileHandle;
}

bool BGE::System::
FileWindows::Close()
{
	CloseHandle(fileHandle);
	fileHandle = nullptr;
	return true;
}

bool BGE::System::
FileWindows::SetFilename(const char* name, size_t length)
{
	/*
		if the filename exists, this is going to be a new file, so lets close the old file.
		we then copy the filename to our buffer and make it null terminated.
	*/
	if (fileName != nullptr)
	{
		Close();
		delete fileName;
		fileNameLength = 0;
	}
	fileName = new char[length + 1];
	memcpy(fileName, name, length * sizeof(char));
	fileName[length] = 0;
	fileNameLength = length;
	return true;
}

char BGE::System::
FileWindows::ReadChar()
{
	if (EndOfFile())
	{
		return -1;
	}
	char buffer = 0;
	unsigned long numRead = 0;
	if (ReadFile(fileHandle, &buffer, sizeof(char), &numRead, NULL))
	{
		lastChar = buffer;
		// EOF, havent included stdio.h where EOF (-1) is defined because it seems to cause conflicts.
		if (buffer == -1)
		{
			isEndOfFile = true;
			currentOffset += sizeof(char);
			return buffer;
		}
	}
	return 0;
}

const char* BGE::System::
FileWindows::ReadLine()
{
	return false;
}

const char* BGE::System::
FileWindows::ReadString()
{
	char buffer[1024] = {0};
	unsigned long bytesRead = 0;
	unsigned long totalBytes = 0;
	char* content = nullptr;
	unsigned long contentPosition = 0;
	// read file until you can't read no more.
	while (ReadFile(fileHandle, &buffer, 1024, &bytesRead, NULL))
	{
		totalBytes += 1024;
		void* newptr = realloc(content, totalBytes);
		if (newptr)
		{	// expand our content buffer and copy the new data onto the end of it.
			content = (char*)newptr;
			memcpy(content + contentPosition, buffer, bytesRead);
			contentPosition += bytesRead;
		}
		else
		{
			assert("out of memory!");
		}
		currentOffset += totalBytes;
		isEndOfFile = true;
		// make content null terminated
		newptr = realloc(content, totalBytes + 1);
		if (newptr)
		{	
			content = (char*)newptr;
			content[totalBytes] = 0;
		}
		else
		{
			assert("out of memory!");
		}
		return content;
	}
	return nullptr;
}

bool BGE::System::
FileWindows::IsOpen()
{
	return isOpen;
}

bool BGE::System::
FileWindows::EndOfFile()
{
	return isEndOfFile;
}

bool BGE::System::
FileWindows::OpenInput()
{
	mode = Mode::BGE_F_READ;
	return Open();
}

bool BGE::System::
FileWindows::OpenOutput()
{
	mode = Mode::BGE_F_WRITE;
	return Open();
}

long BGE::System::
FileWindows::CurrentOffset()
{
	return currentOffset;
}

void BGE::System::
FileWindows::SetMode(IFile::Mode mode)
{
	this->mode = mode;
}

void BGE::System::
FileWindows::SetShareMode(IFile::Share share)
{
	this->share = share;
}

bool BGE::System::
FileWindows::Purge()
{
	Close();
	return DeleteFile(fileName);
}

bool BGE::System::
FileWindows::Rename(const char* newFileName)
{
	if (fileName)
	{
		if (fileHandle)
			Close();
		if (MoveFile(fileName, newFileName))
		{
			SetFilename(newFileName, strlen(newFileName));
			return true;
		}
	}
	return false;
}

bool BGE::System::
FileWindows::Seek(IFile::Position from, long long distance)
{
	long* higherBit = (long*)&distance;
	SetFilePointer(fileHandle, distance, higherBit++, from);
	return true;
}
