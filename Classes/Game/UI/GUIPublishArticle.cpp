#include "GUIPublishArticle.h"

GUIPublishArticle* GUIPublishArticle::createGUI()
{
	auto gui = GUIPublishArticle::create();
	return gui;
}

bool GUIPublishArticle::init()
{
	auto rootNode = CSLoader::createNode("CocosStudio/GUIPublishArticle.csb");
	this->addChild(rootNode);
	registerUI(rootNode);
	initEvent();
	onRefresh();
	return true;
}

void GUIPublishArticle::registerUI(Node* rootNode)
{
	back_button = (Button*)rootNode->getChildByName("back_button");
	add_item_button = (Button*)rootNode->getChildByName("add_item_button");
	add_choose_lay = (Node*)rootNode->getChildByName("add_choose_lay");
	add_title_btn = (Button*)rootNode->getChildByName("add_title_btn");
	add_text_btn = (Button*)rootNode->getChildByName("add_text_btn");
	add_picture_btn = (Button*)rootNode->getChildByName("add_picture_btn");

	showAddItemLay(false);
}

void GUIPublishArticle::initEvent()
{
	back_button->addClickEventListener(CC_CALLBACK_1(GUIPublishArticle::onBackBtnClick, this));
	add_item_button->addClickEventListener(CC_CALLBACK_1(GUIPublishArticle::onAddItemBtnClick, this));
}

void GUIPublishArticle::onRefresh()
{

}

void GUIPublishArticle::onBackBtnClick(Ref *pSender)
{
	this->getParent()->removeChild(this);
}

void GUIPublishArticle::onAddItemBtnClick(Ref *pSender)
{
	showAddItemLay(true);
}

void GUIPublishArticle::showAddItemLay(bool show)
{
	add_choose_lay->setVisible(show);
	auto winSize = Director::getInstance()->getWinSize();
	auto from = winSize.height * 1.5f;
	auto to = winSize * 0.5f;
	add_choose_lay->runAction(MoveTo::create(1, to));
}