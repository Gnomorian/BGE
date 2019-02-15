#include <windows.h>
#include <iostream>
#include "scene.h"

typedef void(__cdecl *WriteStuff)(void);
typedef Scene*(__cdecl *GetScene)(void);

int main()
{
	printf("%s(%d)\n", __FUNCTION__, __LINE__);
	HMODULE handle = LoadLibrary("x64\\Debug\\TestGame.dll");
	if (handle)
	{
		WriteStuff proc;
		proc = (WriteStuff) GetProcAddress(handle, "WriteStuff");
		if (proc)
		{
			(proc)();
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

	FreeLibrary(handle);
}