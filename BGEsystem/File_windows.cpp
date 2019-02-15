#include "File.h"
#include <assert.h>

using namespace BGE;
using namespace System;

FileWindows::FileWindows()
{
	fileHandle = nullptr;
	mode = Mode::F_READ | Mode::F_WRITE;
	share = FILE_SHARE_READ;
}

FileWindows::~FileWindows()
{
	CloseHandle(fileHandle);
}

bool FileWindows::Open()
{
	if (fileHandle != nullptr)
	{
		return false;
	}
	fileHandle = CreateFile(fileName, mode, share, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	return (bool)fileHandle;
}

bool FileWindows::Close()
{
	CloseHandle(fileHandle);
	fileHandle = nullptr;
	return true;
}

bool FileWindows::SetFilename(const char* name, int length)
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

char FileWindows::ReadChar()
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

const char* FileWindows::ReadLine()
{
	return false;
}

const char* FileWindows::ReadString()
{
	char buffer[1024] = {0};
	unsigned long bytesRead = 0;
	unsigned long totalBytes = 0;
	char* content = nullptr;
	unsigned long contentPosition = 0;
	// read file until you cant read no more.
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
			assert("out of memory! %s(%s) %s", __FUNCTION__, __LINE__, __FILE__);
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
			assert("out of memory! %s(%s) %s", __FUNCTION__, __LINE__, __FILE__);
		}
		return content;
	}
	return nullptr;
}

bool FileWindows::IsOpen()
{
	return isOpen;
}

bool FileWindows::EndOfFile()
{
	return isEndOfFile;
}

bool FileWindows::OpenInput()
{
	mode = Mode::F_READ;
	return Open();
}

bool FileWindows::OpenOutput()
{
	mode = Mode::F_WRITE;
	return Open();
}

long FileWindows::CurrentOffset()
{
	return currentOffset;
}

void FileWindows::SetMode(IFile::Mode mode)
{
	this->mode = mode;
}

void FileWindows::SetShareMode(IFile::Share share)
{
	this->share = share;
}

bool FileWindows::Purge()
{
	Close();
	return DeleteFile(fileName);
}

bool FileWindows::Rename(const char* newFileName)
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

bool FileWindows::Seek(IFile::Position from, long long distance)
{
	long* higherBit = (long*)&distance;
	SetFilePointer(fileHandle, distance, higherBit++, from);
	return true;
}