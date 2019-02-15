#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

namespace BGE
{
	namespace System
	{
		struct BGEexception : std::exception
		{
			const char* message;
			int line;
			const char* function;
			const char* file;
			BGEexception(const char* msg, int pLine, const char* pFunction, const char* pFile, ...) : std::exception(msg), 
				message(msg), 
				line(pLine), 
				function(pFunction), 
				file(pFile) 
			{
				//TODO: add processing to check for %s and search for them in va_args
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
