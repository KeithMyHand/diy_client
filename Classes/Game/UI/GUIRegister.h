#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Net\TaskRequest.h"

USING_NS_CC;
using namespace ui;

class GUIRegister : public cocos2d::Layer
{
public:
	static GUIRegister* createGUI();

	virtual bool init();

	CREATE_FUNC(GUIRegister);

private:
	TextField* user_name;
	Text* _user_name_value_label;
	TextField* password;
	Text* _password_value_label;
	TextField* password_again;
	Text* _password_again_value_label;
	Button* back_btn;
	Button* register_btn;

	void registerUI(Node* rootNode);
	void initEvent();
	void onRefresh();
	void userNameEvent(Ref *pSender, TextFiledEventType type);
	void passwordEvent(Ref *pSender, TextFiledEventType type);
	void passwordAgainEvent(Ref *pSender, TextFiledEventType type);
	void onBackBtnClick(Ref *pSender);
	void onRegisterBtnClick(Ref *pSender);
	void onRegisterRequestCompleted(HttpClient *sender, HttpResponse *response);
};