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
	

	/*
	printf("%s(%d)\n", __FUNCTION__, __LINE__);
	HMODULE handle = LoadLibrary("x64\\Debug\\TestGame.dll");
	if (handle)
	{
		void* proc;
		proc = GetProcAddress(handle, "WriteStuff");
		if (proc)
		{
			((WriteStuff)proc)();
			getchar();
		}
		else
		{
			printf("proc is null, %d error occoured.\n", GetLastError());
			getchar();
			return -1;
		}
		
		GetScene scene;
		scene = (GetScene)GetProcAddress(handle, "GetScene");
		if (scene)
		{
			Scene* scn = (scene)();
			if (scn)
			{
				scn->Draw();
				scn->Load();
				scn->Update();
			}
			getchar();
				
				
		}
	}
	else
	{
		printf("handle is null, %d error occoured.\n", GetLastError());
		getchar();
		return -1;
	}

	FreeLibrary(handle);/**/
}