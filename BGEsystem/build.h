#ifndef BGE_BUILD_H
#define BGE_BUILD_H

// here define SFML modules, as i replace them with my own alternatives, undefine them.
#define SFML_GRAPHICS
#define SFML_AUDIO
#define SFML_NETWORK

// define if its windows or not

#define BGE_WINDOWS

#ifndef BGE_WINDOWS
#define BGE_LINUX
#endif // !BGE_WINDOWS

// define macros for exporting 
#define EXPORT __declspec(dllexport)


#endif // !BGE_BUILD_H