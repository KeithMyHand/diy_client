#pragma once
#include "cocos2d.h"

USING_NS_CC;

class DataUtils
{
public:
	static void setIntValue(const char* pKey, const int &intValue);
	static void setFloatValue(const char* pKey, const float &floatValue);
	static void setDoubleValue(const char* pKey, const double &doubleValue);
	static void setBoolValue(const char* pKey, const bool &boolValue);
	static void setStringValue(const char* pKey, const std::string &stringValue);

	static int getIntValue(const char* pKey);
	static float getFloatValue(const char* pKey);
	static double getDoubleValue(const char* pKey);
	static bool getBoolValue(const char* pKey);
	static std::string getStringValue(const char* pKey);
};