#include "GUILoading.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

GUILoading* GUILoading::createGUI()
{
	auto gui = GUILoading::create();
	return gui;
}

bool GUILoading::init()
{
	auto rootNode = CSLoader::createNode("CocosStudio/GUILoading.csb");
	this->addChild(rootNode);
	return true;
}