#ifndef BGE_FILE_SYSTEM_H
#define BGE_FILE_SYSTEM_H

#include "build.h"

namespace BGE
{
	namespace System
	{
		class IFileSystem
		{
		public:
			IFileSystem();
			~IFileSystem();
		};

#ifdef BGE_WINDOWS
#define FilesSystem BGE::System::FileSystemWindows
		class FileSystemWindows
		{
			FileSystemWindows();
			~FileSystemWindows();
			const char* GetWorkingDirectory();

		};

#else
#endif // BGE_WINDOWS
	}
}

#endif // !FILE_SYSTEM_H