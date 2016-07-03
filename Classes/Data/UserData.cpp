#include "UserData.h"
#include <string>

UserData::UserData()
{
}


UserData::~UserData()
{
}

void UserData::setName(char* _name)
{
	strcpy(name, _name);
}

void UserData::setSign(char* _sign)
{
	strcpy(sign, _sign);
}

void UserData::setLevel(int _level)
{
	level = _level;
}

char* UserData::getName()
{
	return name;
}

char* UserData::getSign()
{
	return sign;
}

int UserData::getLevel()
{
	return level;
}