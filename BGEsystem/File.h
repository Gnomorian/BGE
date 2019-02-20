#ifndef BGE_FILE_H
#define BGE_FILE_H

#include "build.h"

namespace BGE
{
	namespace System
	{
		class EXPORT IFile
		{
		protected:
			char* fileName;
			size_t fileNameLength;
			bool isOpen;
			int mode;
			int share;
			int currentOffset;
			char lastChar;
			bool isEndOfFile;
		public:
			enum Mode
			{
				BGE_F_READ,
				BGE_F_WRITE
			};

			enum Share
			{
				BGE_F_SHARE_READ,
				BGE_F_SHARE_WRITE,
				BGE_F_SHARE_DELETE,
				BGE_F_SHARE_EXCLUSIVE
			};

			enum Position
			{
				BGE_F_BEGINING,
				BGE_F_CURRENT,
				BGE_F_END
			};

			IFile() { fileName = nullptr; fileNameLength = 0; isOpen = false; mode = 0; share = 0; currentOffset = 0; lastChar = -1; isEndOfFile = true; }
			~IFile() { if (fileName) delete fileName; };

			// Opens the file
			virtual bool Open() = 0;
			// closes an open file
			virtual bool Close() = 0;
			// sets the filename to be opened, changes the current file for this object, if it is already set.
			virtual bool SetFilename(const char* name, size_t length) = 0;
			// Returns the next character in the file.
			virtual char ReadChar() = 0;
			// Returns the next line in the file.
			virtual const char* ReadLine() = 0;
			// Returns the specified number of characters from the file.
			virtual const char* ReadString() = 0;
			// Returns true if the specified file is currently open.
			virtual bool IsOpen() = 0;
			// 	Returns true if the end of the file has been reached.
			virtual bool EndOfFile() = 0;
			// Opens the file for output
			virtual bool OpenInput() = 0;
			// Opens the file for input
			virtual bool OpenOutput() = 0;
			// Returns the current offset
			virtual long CurrentOffset() = 0;
			// Sets the File mode to be opened as.
			virtual void SetMode(Mode mode) = 0;
			// restricts access to the file by other processes.
			virtual void SetShareMode(Share share) = 0;
			// Deletes the file and its contents from disk
			virtual bool Purge() = 0;
			// Changes the name of the file.
			virtual bool Rename(const char* newFileName) = 0;
			// Repositions the file pointer at a specified Integer offset from the beginning of the file.
			virtual bool Seek(Position from, long long distance) = 0;
		};

#ifdef BGE_WINDOWS

#include <windows.h>
#define File BGE::System::FileWindows

		class EXPORT FileWindows : public IFile
		{
		private:
			HANDLE fileHandle;
		public:
			typedef enum Mode
			{
				BGE_F_READ = GENERIC_READ,
				BGE_F_WRITE = GENERIC_WRITE
			} Mode;

			enum Share
			{
				BGE_F_SHARE_READ = FILE_SHARE_READ,
				BGE_F_SHARE_WRITE = FILE_SHARE_WRITE,
				BGE_F_SHARE_DELETE = FILE_SHARE_DELETE,
				BGE_F_SHARE_EXCLUSIVE = 0
			};

			enum Position
			{
				BGE_F_BEGINING = FILE_BEGIN,
				BGE_F_CURRENT = FILE_CURRENT,
				BGE_F_END = FILE_END
			};

			FileWindows();
			~FileWindows();
			bool Open() override;
			bool Close() override;
			bool SetFilename(const char* name, size_t length) override;
			char ReadChar() override;
			const char* ReadLine() override;
			const char* ReadString() override;
			bool IsOpen() override;
			bool EndOfFile() override;
			bool OpenInput() override;
			bool OpenOutput() override;
			long CurrentOffset() override;
			void SetMode(IFile::Mode mode) override;
			void SetShareMode(IFile::Share share) override;
			bool Purge() override;
			bool Rename(const char* newFileName) override;
			bool Seek(IFile::Position from, long long distance) override;
			
		};
#else // just get windows working first, this is here as a shame thing, if I dont add it.
#define File FileLinux
#define File BGE::System::LinuxFile
		
#endif // BGE_WINDOWS
	}
}

#endif