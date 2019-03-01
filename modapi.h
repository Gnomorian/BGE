#ifndef BGE_MODAPI_H
#define BGE_MODAPI_H

#define CALL __stdcall

#include "BGEsystem/Mod.h"

#ifdef _CORE
#define MODAPI extern "C" __declspec(dllimport)

typedef BGE::System::IGame*(__cdecl *AlienGetGame)(void);
typedef BGE::System::IMod*(__cdecl *AlienGetMod)(void);

#else
#define MODAPI extern "C" __declspec(dllexport)

MODAPI BGE::System::IGame* CALL AlienGetGame();
MODAPI BGE::System::IMod* CALL AlienGetMod();

#endif

#endif // !MODAPI_H
