#pragma once
#include "cocos2d.h"

class GUILoading : public cocos2d::Layer
{
public:
	static GUILoading* createGUI();

	virtual bool init();

	CREATE_FUNC(GUILoading);

};