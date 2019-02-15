#pragma once
#include "scene.h"

class SCENE_IE MyScene : public Scene
{
public:
	MyScene();
	~MyScene();
	void Load();
	void Update();
	void Draw();
};

