#ifndef BGE_MODAPI_H
#define BGE_MODAPI_H

#define CALL __stdcall

#ifdef _CORE
#define MODAPI extern "C" __declspec(dllimport)

typedef void(__cdecl *WriteStuff)(void);

#else
#define MODAPI extern "C" __declspec(dllexport)

MODAPI void CALL WriteStuff();

#endif

#endif // !MODAPI_H
