#include "UserMan.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
#include "cocos2d.h"

using namespace cocos2d;

UserMan* UserMan::m_pInstance = nullptr;

void UserMan::onInit()
{
	if (userData == nullptr)
	{
		userData = new UserData();
	}
}

void UserMan::setUserData(char* jsonData)
{
	rapidjson::Document readdoc;
	readdoc.Parse<0>(jsonData);
	if (readdoc.HasParseError())
	{
		LOGERROR("Parse User Data Error: %s\n", readdoc.GetParseError());
	}
	if (!readdoc.IsObject())
	{
		LOGERROR("User Data Json Is Not A Object!");
		return;
	}
	if (readdoc.HasMember("name"))
	{
		const rapidjson::Value &userValue = readdoc["name"];
		const char* name = userValue.GetString(); 
		userData->setName((char*)name);
	}
}

void UserMan::setUserName(char* name)
{
	userData->setName(name);
}

void UserMan::setUserSign(char* sign)
{
	userData->setSign(sign);
}

void UserMan::setUserLevel(int level)
{
	userData->setLevel(level);
}

char* UserMan::getUserName()
{
	return userData->getName();
}

char* UserMan::getUserSign()
{
	return userData->getSign();
}

int UserMan::getUserLevel()
{
	return userData->getLevel();
}