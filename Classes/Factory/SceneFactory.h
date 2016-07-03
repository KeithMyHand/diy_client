#pragma once
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;
class SceneFactory
{
public:
	SceneFactory();
	~SceneFactory();

public:
	static Scene* createScene(string sceneName);
};

