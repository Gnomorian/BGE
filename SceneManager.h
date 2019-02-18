#ifndef BGE_SCENE_MANAGER_H
#define BGE_SCENE_MANAGER_H

#include "scene.h"
#include <map>

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

#endif // !BGE_SCENE_H