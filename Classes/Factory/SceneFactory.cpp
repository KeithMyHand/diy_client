#include "SceneFactory.h"
#include "Game\Scene\GameScene.h"

SceneFactory::SceneFactory()
{
}

SceneFactory::~SceneFactory()
{
}

Scene* SceneFactory::createScene(string sceneName)
{
	if (sceneName == "GameScene")
		return GameScene::createScene();
	else
		return NULL;
}