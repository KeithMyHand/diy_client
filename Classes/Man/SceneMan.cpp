#include "SceneMan.h"
#include "Factory\SceneFactory.h"

SceneMan* SceneMan::m_pInstance = nullptr;

void SceneMan::onInit()
{

}

Scene* SceneMan::getCrrentScene()
{
	return m_pCurrentScene;
}

void SceneMan::pushScene(string sceneName)
{
	auto iter = scenes.find(sceneName);
	if (iter != scenes.end())
	{
		CCLOG("scene has already bean pushed!");
	}
	else
	{
		m_pCurrentScene = SceneFactory::createScene(sceneName);
		Director::getInstance()->runWithScene(m_pCurrentScene);
		CCLOG("\nPushed Scene : %s\n", sceneName.c_str());
	}
}

void SceneMan::popScene()
{

}