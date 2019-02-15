#ifndef MODAPI_H
#define MODAPI_H

#ifdef _CORE
#define MODAPI extern "C" __declspec(dllimport)
#else
#define MODAPI extern "C" __declspec(dllexport)
#endif

#define CALL __stdcall

#include "scene.h"
	MODAPI void CALL WriteStuff();
	MODAPI Scene* CALL GetScene();

#endif // !MODAPI_H
