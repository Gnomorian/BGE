#include <windows.h>
#include <iostream>
#include "scene.h"
#include "BGEsystem/AlienLib.h"
#include "BGEsystem/Exception.h"

typedef void(__cdecl *WriteStuff)(void);
typedef Scene*(__cdecl *GetScene)(void);

int main()
{
	try
	{
		AlienLib lib("x64\\Debug\\TestGame.dll");
		lib.Load();
		WriteStuff stuff = (WriteStuff)lib.GetFunction("WriteStuff");
		(stuff)();
	}
	catch (BGE::System::BGEexception& e)
	{
		printf("%s %s(%d) \"%s\"\n", e.GetMsg(), e.GetFunction(), e.GetLine(), e.GetFile());
		getchar();
		exit(-1);
	}

	getchar();
	return 0;
}