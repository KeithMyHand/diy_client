#include "DataUtils.h"

void DataUtils::setIntValue(const char* pKey, const int &intValue)
{
	CCUserDefault::getInstance()->setIntegerForKey(pKey, intValue);
	CCUserDefault::getInstance()->flush();
}

void DataUtils::setFloatValue(const char* pKey, const float &floatValue)
{
	CCUserDefault::getInstance()->setFloatForKey(pKey, floatValue);
	CCUserDefault::getInstance()->flush();
}

void DataUtils::setDoubleValue(const char* pKey, const double &doubleValue)
{
	CCUserDefault::getInstance()->setDoubleForKey(pKey, doubleValue);
	CCUserDefault::getInstance()->flush();
}

void DataUtils::setBoolValue(const char* pKey, const bool &boolValue)
{
	CCUserDefault::getInstance()->setBoolForKey(pKey, boolValue);
	CCUserDefault::getInstance()->flush();
}

void DataUtils::setStringValue(const char* pKey, const std::string &stringValue)
{
	CCUserDefault::getInstance()->setStringForKey(pKey, stringValue);
	CCUserDefault::getInstance()->flush();
}

int DataUtils::getIntValue(const char* pKey)
{
	return CCUserDefault::getInstance()->getIntegerForKey(pKey);
}

float DataUtils::getFloatValue(const char* pKey)
{
	return CCUserDefault::getInstance()->getFloatForKey(pKey);
}

double DataUtils::getDoubleValue(const char* pKey)
{
	return CCUserDefault::getInstance()->getDoubleForKey(pKey);
}

bool DataUtils::getBoolValue(const char* pKey)
{
	return CCUserDefault::getInstance()->getBoolForKey(pKey);
}

std::string DataUtils::getStringValue(const char* pKey)
{
	return CCUserDefault::getInstance()->getStringForKey(pKey);
}