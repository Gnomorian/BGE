#ifndef BGE_EXCEPTION_H
#define BGE_EXCEPTION_H

#include <exception>
#include <vector>
#include <string>
#include <iostream>

namespace BGE
{
	namespace System
	{
		struct EXPORT BGEexception : std::exception
		{
			const char* message;
			int line;
			const char* function;
			const char* file;
			BGEexception(const char* msg, int pLine, const char* pFunction, const char* pFile, ...) : std::exception(msg), 
				message(nullptr), 
				line(pLine), 
				function(pFunction), 
				file(pFile) 
			{
				char* buffer = new char[1024];
				memset(buffer, 0, 1024 * sizeof(char));
				va_list args;
				va_start(args, msg);
				sprintf_s(buffer, 1024 * sizeof(char), msg, args);
				va_end(args);
				size_t length = strlen(buffer);
				message = buffer;
			}
			const char* what() const throw()
			{
				return message;
			}
			int GetLine() { return line; }
			const char* GetMsg() { return message; }
			const char* GetFunction() { return function; }
			const char* GetFile() { return file; }
		};
	}
}

#endif // !EXCEPTION_H
