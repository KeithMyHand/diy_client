#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Net\TaskRequest.h"

USING_NS_CC;
using namespace ui;

class GUILogin : public cocos2d::Layer
{
public:
	static GUILogin* createGUI();

	virtual bool init();

	CREATE_FUNC(GUILogin);

private:
	TextField* user_name;
	Text* _user_name_value_label;
	TextField* password;
	Text* _password_value_label;
	Button* login_btn;
	Button* register_btn;
	Button* forget_password_btn;

	void registerUI(Node* rootNode);
	void initEvent();
	void onRefresh();
	void userNameEvent(Ref *pSender, TextFiledEventType type);
	void passwordEvent(Ref *pSender, TextFiledEventType type);
	void onLoginBtnClick(Ref *pSender);
	void onRegisterBtnClick(Ref *pSender);
	void onLoginRequestCompleted(HttpClient *sender, HttpResponse *response);
};