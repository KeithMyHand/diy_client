#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Net\TaskRequest.h"

USING_NS_CC;
using namespace ui;

class GUIUserMain : public cocos2d::Layer
{
public:
	static GUIUserMain* createGUI();

	virtual bool init();

	CREATE_FUNC(GUIUserMain);

private:
	Button* publish_article_button;
	Text* user_name;
	Layout* article_item;
	ListView* article_list;
	Sprite* no_article;
	Sprite* choose_bg;
	Button* main_button;
	Button* hall_button;
	Button* focus_button;

private:
	void registerUI(Node* rootNode);
	void initEvent();
	void onRefresh();
	void onGetUserArticlesRequestCompleted(HttpClient *sender, HttpResponse *response);
	void onPublishArticleBtnClick(Ref *pSender);
	void onMainBtnClick(Ref *pSender);
	void onHallBtnClick(Ref *pSender);
	void onFocusBtnClick(Ref *pSender);
	void onArticleBeClick(Ref *pSender, int id);
};