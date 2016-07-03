#include "GUIRegister.h"
#include "..\..\Man\SceneMan.h"
#include "..\..\Tool\UITool.h"
#include "..\..\Utils\Local.h"
#include "..\..\Utils\DataUtils.h"
#include "..\..\Man\TaskMan.h"

GUIRegister* GUIRegister::createGUI()
{
	auto gui = GUIRegister::create();
	return gui;
}

bool GUIRegister::init()
{
	auto rootNode = CSLoader::createNode("CocosStudio/GUIRegister.csb");
	this->addChild(rootNode);
	registerUI(rootNode);
	initEvent();
	onRefresh();
	return true;
}

void GUIRegister::registerUI(Node* rootNode)
{
	user_name = (TextField*)rootNode->getChildByName("user_name");
	_user_name_value_label = (Text*)rootNode->getChildByName("_user_name_value_label");
	password = (TextField*)rootNode->getChildByName("user_password");
	_password_value_label = (Text*)rootNode->getChildByName("_user_password_value_label");
	password_again = (TextField*)rootNode->getChildByName("user_password_again");
	_password_again_value_label = (Text*)rootNode->getChildByName("_user_password_again_value_label");
	back_btn = (Button*)rootNode->getChildByName("back_btn");
	register_btn = (Button*)rootNode->getChildByName("register_btn");
	user_name->setMaxLengthEnabled(true);
	user_name->setMaxLength(14);
	password->setMaxLengthEnabled(true);
	password->setMaxLength(14);

	back_btn->setPressedActionEnabled(true);
	register_btn->setPressedActionEnabled(true);
}

void GUIRegister::initEvent()
{
	user_name->addEventListenerTextField(this, textfieldeventselector(GUIRegister::userNameEvent));
	password->addEventListenerTextField(this, textfieldeventselector(GUIRegister::passwordEvent));
	password_again->addEventListenerTextField(this, textfieldeventselector(GUIRegister::passwordAgainEvent));
	back_btn->addClickEventListener(CC_CALLBACK_1(GUIRegister::onBackBtnClick, this));
	register_btn->addClickEventListener(CC_CALLBACK_1(GUIRegister::onRegisterBtnClick, this));
}

void GUIRegister::onBackBtnClick(Ref *pSender)
{
	SceneMan::getInstance()->getCrrentScene()->removeChild(this);
}

void GUIRegister::onRegisterBtnClick(Ref *pSender)
{
	std::string userName = user_name->getString();
	std::string userPassword = password->getString();
	std::string userPasswordAgain = password_again->getString();
	if (userName == "")
	{
		UITool::showMessageBox(Local::L("message_dialog_title_error"), Local::L("user_name_is_null"));
		return;
	}
	if (userPassword == "")
	{
		UITool::showMessageBox(Local::L("message_dialog_title_error"), Local::L("user_password_is_null"));
		return;
	}
	if (userPasswordAgain == "")
	{
		UITool::showMessageBox(Local::L("message_dialog_title_error"), Local::L("user_password_again_is_null"));
		return;
	}
	if (userPassword != userPasswordAgain)
	{
		UITool::showMessageBox(Local::L("message_dialog_title_error"), Local::L("user_password_is_not_equal"));
		return;
	}
	TaskMan::getInstance()->registerUser(userName.c_str(), userPassword.c_str(), CC_CALLBACK_2(GUIRegister::onRegisterRequestCompleted, this));
}

void GUIRegister::onRefresh()
{

}

void GUIRegister::userNameEvent(Ref *pSender, TextFiledEventType type)
{
	_user_name_value_label->setText(user_name->getString());
}

void GUIRegister::passwordEvent(Ref *pSender, TextFiledEventType type)
{
	_password_value_label->setText(password->getString());
}

void GUIRegister::passwordAgainEvent(Ref *pSender, TextFiledEventType type)
{
	_password_again_value_label->setText(password_again->getString());
}

void GUIRegister::onRegisterRequestCompleted(HttpClient *sender, HttpResponse *response)
{
	if (!response)
	{
		return;
	}
	if (!response->isSucceed())
	{
		LOGERROR("onRegisterRequestCompleted response failed! error buffer: %s", response->getErrorBuffer());
		return;
	}
	std::vector<char> *buffer = response->getResponseData();
	std::string str(buffer->begin(), buffer->end());
	LOGINFO("onRegisterRequestCompleted response success! response: %s", str.c_str());
	DataUtils::setStringValue("user_name", user_name->getString());
	DataUtils::setStringValue("user_password", password->getString());
	LOGINFO("write user data success: %s  %s", user_name->getString().c_str(), password->getString().c_str());
}