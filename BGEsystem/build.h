#pragma once
// here define SFML modules, as i replace them with my own alternatives, undefine them.
#define SFML_GRAPHICS
#define SFML_AUDIO
#define SFML_NETWORK

// define if its windows or not

#define BGE_WINDOWS
//#define BGE_LINUX

#define EXPORT __declspec(dllexport)