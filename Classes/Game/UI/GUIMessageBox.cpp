#include "GUIMessageBox.h"

GUIMessageBox* GUIMessageBox::createGUI()
{
	auto gui = GUIMessageBox::create();
	return gui;
}

bool GUIMessageBox::init()
{
	auto rootNode = CSLoader::createNode("CocosStudio/MessageBox.csb");
	this->addChild(rootNode);
	registerUI(rootNode);
	initEvent();
	onRefresh();
	return true;
}

void GUIMessageBox::registerUI(Node* rootNode)
{
	title_text = (Text*)rootNode->getChildByName("title_text");
	content_text = (Text*)rootNode->getChildByName("content_text");
	confirm_btn = (Button*)rootNode->getChildByName("confirm_btn");
	cancel_btn = (Button*)rootNode->getChildByName("cancel_btn");
	confirm_btn->setPressedActionEnabled(true);
	cancel_btn->setPressedActionEnabled(true);
}

void GUIMessageBox::initEvent()
{
	confirm_btn->addClickEventListener(CC_CALLBACK_1(GUIMessageBox::onConfirmBtnClick, this));
	cancel_btn->addClickEventListener(CC_CALLBACK_1(GUIMessageBox::onCancelBtnClick, this));
}

void GUIMessageBox::onConfirmBtnClick(Ref *pSender)
{
	this->getParent()->removeChild(this);
}

void GUIMessageBox::onCancelBtnClick(Ref *pSender)
{
	this->getParent()->removeChild(this);
}

void GUIMessageBox::onRefresh()
{

}

void GUIMessageBox::setTitle(const char* title)
{
	title_text->setText(title);
}

void GUIMessageBox::setContent(const char* content)
{
	content_text->setText(content);
}