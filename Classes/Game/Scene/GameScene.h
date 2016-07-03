#pragma once
#include "cocos2d.h"
#include "..\..\Man\TaskMan.h"

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);

	void preLoginResponse(HttpClient *sender, HttpResponse *response);
	void changeToUserMain(float dt);
	void changeToLoginScene(float dt);
};