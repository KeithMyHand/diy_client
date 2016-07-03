#include "GUILogin.h"
#include "GUIRegister.h"
#include "..\..\Man\TaskMan.h"
#include "..\..\Utils\Local.h"
#include "..\..\Utils\DataUtils.h"
#include "..\..\Tool\UITool.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
#include "..\..\Man\SceneMan.h"
#include "..\..\Man\UserMan.h"
#include "..\UI\GUIUserMain.h"

GUILogin* GUILogin::createGUI()
{
	auto gui = GUILogin::create();
	return gui;
}

bool GUILogin::init()
{
	auto rootNode = CSLoader::createNode("CocosStudio/GUILogin.csb");
	this->addChild(rootNode);
	registerUI(rootNode);
	initEvent();
	onRefresh();
	return true;
}

void GUILogin::registerUI(Node* rootNode)
{
	user_name = (TextField*)rootNode->getChildByName("user_name");
	_user_name_value_label = (Text*)rootNode->getChildByName("_user_name_value_label");
	password = (TextField*)rootNode->getChildByName("password");
	_password_value_label = (Text*)rootNode->getChildByName("_password_value_label");
	login_btn = (Button*)rootNode->getChildByName("login_btn");
	register_btn = (Button*)rootNode->getChildByName("register_btn");
	forget_password_btn = (Button*)rootNode->getChildByName("forget_password_btn");
	user_name->setMaxLengthEnabled(true);
	user_name->setMaxLength(14);
	password->setMaxLengthEnabled(true);
	password->setMaxLength(14);

	login_btn->setPressedActionEnabled(true);
	register_btn->setPressedActionEnabled(true);
}

void GUILogin::initEvent()
{
	user_name->addEventListenerTextField(this, textfieldeventselector(GUILogin::userNameEvent));
	password->addEventListenerTextField(this, textfieldeventselector(GUILogin::passwordEvent));
	login_btn->addClickEventListener(CC_CALLBACK_1(GUILogin::onLoginBtnClick, this));
	register_btn->addClickEventListener(CC_CALLBACK_1(GUILogin::onRegisterBtnClick, this));
}

rapidjson::Document doc;
void GUILogin::onLoginBtnClick(Ref *pSender)
{
	const char* name = _user_name_value_label->getString().c_str();
	const char* password = _password_value_label->getString().c_str();
	DataUtils::setStringValue("user_name", name);
	DataUtils::setStringValue("user_password", password);
	TaskMan::getInstance()->login(name, password, CC_CALLBACK_2(GUILogin::onLoginRequestCompleted, this));
}

void GUILogin::onRegisterBtnClick(Ref *pSender)
{
	auto gui = GUIRegister::createGUI();
	SceneMan::getInstance()->getCrrentScene()->addChild(gui);
}

void GUILogin::onRefresh()
{

}

void GUILogin::userNameEvent(Ref *pSender, TextFiledEventType type)
{
	_user_name_value_label->setText(user_name->getString());
}

void GUILogin::passwordEvent(Ref *pSender, TextFiledEventType type)
{
	_password_value_label->setText(password->getString());
}

void GUILogin::onLoginRequestCompleted(HttpClient *sender, HttpResponse *response)
{
	if (!response)
	{
		return;
	}
	if (!response->isSucceed())
	{
		LOGERROR("onLoginRequestCompleted response failed! error buffer: %s", response->getErrorBuffer());
		return;
	}
	std::vector<char> *buffer = response->getResponseData();
	std::string str(buffer->begin(), buffer->end());
	LOGINFO("onLoginRequestCompleted response success! response: %s", str.c_str());
	if (str == "NO_USER")
	{
		UITool::showMessageBox(Local::L("message_dialog_title_error"), Local::L("user_or_password_is_wrong"));
	}
	else
	{
		UserMan::getInstance()->setUserData((char*)str.c_str());
		auto gui = GUIUserMain::createGUI();
		this->addChild(gui);
	}
}