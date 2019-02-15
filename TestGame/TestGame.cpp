#include "modapi.h"
#include "MyScene.h"
#include <iostream>

Scene* GetScene()
{
	MyScene* scene = new MyScene;
	return scene;
}

void WriteStuff()
{
	printf("Hello, isnt it a beautiful world!\nArnt you learning stufff!");
}