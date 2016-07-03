#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace ui;

class GUIUserAticleItem : public Widget
{
public:
	GUIUserAticleItem();
	~GUIUserAticleItem();

private:
	Node* item;

public:
	void setItem(Node* _item);
};