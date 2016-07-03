#pragma once
#include "cocos2d.h"
#include <map>

using namespace std;
using namespace cocos2d;
class SceneMan
{
private:
	static SceneMan* m_pInstance;
public:
	static SceneMan* getInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new SceneMan();
		return m_pInstance;
	}
	~SceneMan();
	void onInit();

private:
	Scene* m_pCurrentScene;
	map<string, Scene*> scenes;
public:
	Scene* getCrrentScene();
	void pushScene(string sceneName);
	void popScene();
};