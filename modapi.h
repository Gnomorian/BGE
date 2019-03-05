#ifndef BGE_MODAPI_H
#define BGE_MODAPI_H

#define CALL __stdcall

#include "BGEsystem/Mod.h"

#ifdef _CORE
#define MODAPI extern "C" __declspec(dllimport)

typedef BGE::System::IGame*(__cdecl *LoadBGEMod)(void);

#else
#define MODAPI extern "C" __declspec(dllexport)

MODAPI BGE::System::IGame* CALL LoadBGEMod();

#endif

#endif // !MODAPI_H
