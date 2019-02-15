#pragma once

#include <map>
#include "scene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void BeginScene(const char* name);
	void AddScene(const char* name, Scene* scene);

private:
	std::map<const char*, Scene*> scenes;
};

