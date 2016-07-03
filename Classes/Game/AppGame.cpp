#include "AppGame.h"
#include "Utils\Local.h"

AppGame::AppGame()
{
	m_pManRegister = new ManRegister();
}

AppGame::~AppGame()
{
}

void AppGame::onInit()
{
	m_pManRegister->registerMans();
	onInitConfig();
}

void AppGame::onInitConfig()
{
	Local::onInitDictionary("Local/string.xml");
}