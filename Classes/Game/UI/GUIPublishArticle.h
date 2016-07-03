#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class GUIPublishArticle : public cocos2d::Layer
{
public:
	static GUIPublishArticle* createGUI();

	virtual bool init();

	CREATE_FUNC(GUIPublishArticle);

private:
	Button* back_button;
	Button* add_item_button;
	Node* add_choose_lay;
	Button* add_title_btn;
	Button* add_text_btn;
	Button* add_picture_btn;

private:
	void registerUI(Node* rootNode);
	void initEvent();
	void onRefresh();
	void onBackBtnClick(Ref *pSender);
	void onAddItemBtnClick(Ref *pSender);
	void showAddItemLay(bool show);
};