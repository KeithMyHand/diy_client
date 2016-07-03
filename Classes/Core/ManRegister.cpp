#include "ManRegister.h"
#include "Man\SceneMan.h"
#include "Man\UIMan.h"
#include "Man\TaskMan.h"
#include "Man\UserMan.h"
#include "Man\NetMan.h"
#include "Man\ArticleMan.h"

ManRegister::ManRegister()
{
}

ManRegister::~ManRegister()
{
}

void ManRegister::registerMans()
{
	NetMan::getInstance()->onInit();
	SceneMan::getInstance()->onInit();
	UIMan::getInstance()->onInit();
	TaskMan::getInstance()->onInit();
	UserMan::getInstance()->onInit();
	ArticleMan::getInstance()->onInit();
}