#ifndef BGE_SCENE_H
#define BGE_SCENE_H

#ifdef _CORE
#define SCENE_IE __declspec(dllimport)
#else
#define SCENE_IE __declspec(dllexport)
#endif // _EXPORT


class SCENE_IE Scene
{
public:
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

#endif // !SCENE_H
