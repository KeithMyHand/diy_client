#include "GameScene.h"
#include "..\UI\GUILoading.h"
#include "..\UI\GUILogin.h"
#include "..\..\Man\SceneMan.h"
#include "..\..\Man\UserMan.h"
#include "..\..\Utils\DataUtils.h"
#include "..\UI\GUIUserMain.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto gui = GUILoading::createGUI();
	this->addChild(gui);
	std::string userName = DataUtils::getStringValue("user_name");
	std::string userPassword = DataUtils::getStringValue("user_password");
	if (userName != "" && userPassword != "")
	{
		TaskMan::getInstance()->preLogin(userName.c_str(), userPassword.c_str(), CC_CALLBACK_2(GameScene::preLoginResponse, this));
	}
	else
	{
		this->scheduleOnce(schedule_selector(GameScene::changeToLoginScene), 2.0f);
	}
	return true;
}

void GameScene::preLoginResponse(HttpClient *sender, HttpResponse *response)
{
	if (!response)
	{
		return;
	}
	if (!response->isSucceed())
	{
		LOGERROR("onRegisterRequestCompleted response failed! error buffer: %s", response->getErrorBuffer());
		return;
	}
	std::vector<char> *buffer = response->getResponseData();
	std::string str(buffer->begin(), buffer->end());
	LOGINFO("changeToUserMain response success! response: %s", str.c_str());
	if (str != "NO_USER")
	{
		UserMan::getInstance()->setUserData((char*)str.c_str());
		this->scheduleOnce(schedule_selector(GameScene::changeToUserMain), 2.0f);
		LOGINFO("HAS_USER PreLogin success!");
	}
	else
	{
		DataUtils::setStringValue("user_name", "");
		DataUtils::setStringValue("user_password", "");
		this->scheduleOnce(schedule_selector(GameScene::changeToLoginScene), 2.0f);
		LOGERROR("NO_USER Locale data has deleted!");
	}

}

void GameScene::changeToUserMain(float dt)
{
	auto gui = GUIUserMain::createGUI();
	this->addChild(gui);
}

void GameScene::changeToLoginScene(float dt)
{
	auto gui = GUILogin::createGUI();
	this->addChild(gui);
}