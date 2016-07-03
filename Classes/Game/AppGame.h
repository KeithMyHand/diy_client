#pragma once
#include "Core\ManRegister.h"
#include "cocos2d.h"

USING_NS_CC;

class AppGame
{
public:
	AppGame();
	~AppGame();
private:
	ManRegister* m_pManRegister;
public:
	void onInit();
	void onInitConfig();
};

