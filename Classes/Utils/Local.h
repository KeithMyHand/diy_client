#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Local
{
private:
	static CCDictionary* dictionary;

public:
	static void onInitDictionary(const char* string);
	static const char* L(const char* string);
};