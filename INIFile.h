#ifndef BGE_INIFILE_H
#define BGE_INIFILE_H

#include "BGEsystem/build.h"
#include "BGEsystem/File.h"

namespace BGE
{
	namespace Engine
	{
		enum Datatype
		{
			INI_BOOL,
			INI_STRING,
			INI_INT
		};

		struct Setting
		{
			Datatype datatype;
			char* category;
			char* value;
		};

		struct Category
		{
			char* name;
			Setting** settings;
		};

		class INIFile
		{
		private:
			File* file;
			void ParseInifile();
			void FlushInifile();
		public:
			INIFile();
			INIFile(const char* fileName, int length);
			~INIFile();
			const char* GetIniFilename();
			const char* GetWorkingDirectory();
			int GetInt(const char* category, const char* setting, int defaultValue);
			const char* GetString(const char* category, const char* setting, const char* defaultValue);
			int GetBool(const char* category, const char* setting, bool defaultValue);
		};
	}
}

#endif // !INIFILE_H