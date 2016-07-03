#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class GUIMessageBox : public cocos2d::Layer
{
public:
	static GUIMessageBox* createGUI();

	virtual bool init();

	CREATE_FUNC(GUIMessageBox);

private:
	Text* title_text;
	Text* content_text;
	Button* confirm_btn;
	Button* cancel_btn;

	void registerUI(Node* rootNode);
	void initEvent();
	void onRefresh();
	void onConfirmBtnClick(Ref *pSender);
	void onCancelBtnClick(Ref *pSender);

public:
	void setTitle(const char* title);
	void setContent(const char* content);
};