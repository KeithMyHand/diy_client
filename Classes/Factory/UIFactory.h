#pragma once
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;
class UIFactory
{
public:
	UIFactory();
	~UIFactory();
public:
	static Node* createUI(string name);
};

