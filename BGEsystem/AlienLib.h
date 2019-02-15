#ifndef ALIEN_LIB_H
#define ALIEN_LIB_H
#include <Windows.h>
#include "build.h"

namespace BGE
{
	namespace System
	{
		class EXPORT IAlienLib
		{
		protected:
			char* fileName;
		public:
			IAlienLib() { fileName = nullptr; }
			virtual void SetFilename(const char* name) = 0;
			virtual void SetFilename(const char* name, size_t length) = 0;
			virtual const char* GetFilename() = 0;
			virtual void* GetFunction(const char* funcName) = 0;
			virtual bool Load() = 0;
			virtual bool Unload() = 0;
		};

#ifdef BGE_WINDOWS
#define AlienLib BGE::System::WindowsAlienLib

		class EXPORT WindowsAlienLib : public IAlienLib
		{
		private:
			HMODULE handle;
		public:
			WindowsAlienLib(const char* name);
			WindowsAlienLib();
			~WindowsAlienLib();
			void SetFilename(const char* name);
			void SetFilename(const char* name, size_t length);
			const char* GetFilename();
			void* GetFunction(const char* funcName);
			bool Load();
			bool Unload();
		};

#else
#define AlienLib LinuxAlienLib
		//TODO: linux implementation
#endif // BGE_WINDOWS
	}
}
#endif // !ALIEN_LIB_H


