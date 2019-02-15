#ifndef WINDOW_H
#define WINDOW_H

#include "build.h"

class EXPORT IWindow
{
public:
	IWindow();
	~IWindow();
};

#ifdef SFML_GRAPHICS

class EXPORT SFMLWindow : public IWindow
{
	SFMLWindow();
	~SFMLWindow();
};

#endif // SFML_GRAPHICS


#endif // !WINDOW_H