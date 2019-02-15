#include "MyScene.h"

#include <iostream>

MyScene::MyScene()
{
}


MyScene::~MyScene()
{
}

void MyScene::Load()
{
	printf("%s(%d)\n", __FUNCTION__, __LINE__);
}

void MyScene::Update()
{
	printf("%s(%d)\n", __FUNCTION__, __LINE__);
}

void MyScene::Draw()
{
	printf("%s(%d)\n", __FUNCTION__, __LINE__);
}