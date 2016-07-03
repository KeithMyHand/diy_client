#include "GUIUserMain.h"
#include "..\..\Man\UserMan.h"
#include "..\..\Man\UIMan.h"
#include "..\..\Man\TaskMan.h"
#include "..\..\Man\ArticleMan.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"
#include "GUIPublishArticle.h"

GUIUserMain* GUIUserMain::createGUI()
{
	auto gui = GUIUserMain::create();
	return gui;
}

bool GUIUserMain::init()
{
	auto rootNode = CSLoader::createNode("CocosStudio/GUIUserMain.csb");
	this->addChild(rootNode);
	registerUI(rootNode);
	initEvent();
	onRefresh();
	return true;
}

Color3B SelectedColor(109, 197, 250);
Color3B NotSelectedColor(125, 125, 125);
void GUIUserMain::registerUI(Node* rootNode)
{
	publish_article_button = (Button*)rootNode->getChildByName("publish_article_btn");
	user_name = (Text*)rootNode->getChildByName("user_name_label");
	article_item = (Layout*)rootNode->getChildByName("article_item");
	article_list = (ListView*)rootNode->getChildByName("list");
	no_article = (Sprite*)rootNode->getChildByName("no_article");
	no_article->setVisible(false);

	choose_bg = (Sprite*)rootNode->getChildByName("choose_bg");
	main_button = (Button*)rootNode->getChildByName("main_button");
	hall_button = (Button*)rootNode->getChildByName("hall_button");
	focus_button = (Button*)rootNode->getChildByName("focus_button");
	choose_bg->setPositionX(main_button->getPositionX());
	main_button->setColor(SelectedColor);
	hall_button->setColor(NotSelectedColor);
	focus_button->setColor(NotSelectedColor);
}

void GUIUserMain::initEvent()
{
	TaskMan::getInstance()->getUserArticles(UserMan::getInstance()->getUserName(), CC_CALLBACK_2(GUIUserMain::onGetUserArticlesRequestCompleted, this));
	publish_article_button->addClickEventListener(CC_CALLBACK_1(GUIUserMain::onPublishArticleBtnClick, this));
	main_button->addClickEventListener(CC_CALLBACK_1(GUIUserMain::onMainBtnClick, this));
	hall_button->addClickEventListener(CC_CALLBACK_1(GUIUserMain::onHallBtnClick, this));
	focus_button->addClickEventListener(CC_CALLBACK_1(GUIUserMain::onFocusBtnClick, this));
}

void GUIUserMain::onPublishArticleBtnClick(Ref *pSender)
{
	auto gui = GUIPublishArticle::createGUI();
	this->addChild(gui);
}

void GUIUserMain::onMainBtnClick(Ref *pSender)
{
	main_button->setColor(SelectedColor);
	hall_button->setColor(NotSelectedColor);
	focus_button->setColor(NotSelectedColor);
	choose_bg->runAction(EaseElasticOut::create(MoveTo::create(0.2f, main_button->getPosition())));
}

void GUIUserMain::onHallBtnClick(Ref *pSender)
{
	main_button->setColor(NotSelectedColor);
	hall_button->setColor(SelectedColor);
	focus_button->setColor(NotSelectedColor);
	choose_bg->runAction(EaseElasticOut::create(MoveTo::create(0.2f, hall_button->getPosition())));
}

void GUIUserMain::onFocusBtnClick(Ref *pSender)
{
	main_button->setColor(NotSelectedColor);
	hall_button->setColor(NotSelectedColor);
	focus_button->setColor(SelectedColor);
	choose_bg->runAction(EaseElasticOut::create(MoveTo::create(0.2f, focus_button->getPosition())));
}

void GUIUserMain::onRefresh()
{
	user_name->setText(UserMan::getInstance()->getUserName());
}

void GUIUserMain::onGetUserArticlesRequestCompleted(HttpClient *sender, HttpResponse *response)
{
	if (!response)
	{
		return;
	}
	if (!response->isSucceed())
	{
		LOGERROR("onGetUserArticlesRequestCompleted response failed! error buffer: %s", response->getErrorBuffer());
		return;
	}
	std::vector<char> *buffer = response->getResponseData();
	std::string jsonData(buffer->begin(), buffer->end());
	LOGINFO("onGetUserArticlesRequestCompleted response success! response: %s", jsonData.c_str());

	rapidjson::Document readdoc;
	readdoc.Parse<0>(jsonData.c_str());
	if (readdoc.HasParseError())
	{
		LOGERROR("Parse User Data Error: %s\n", readdoc.GetParseError());
	}
	if (readdoc.IsArray())
	{
		auto length = readdoc.Capacity();
		no_article->setVisible(length <= 0);
		if (length > 0)
		{
			for (int index = 0; index < length; index++)
			{
				auto id = readdoc[index]["id"].GetInt();
				auto title = readdoc[index]["title"].GetString();
				auto des = readdoc[index]["des"].GetString();
				auto icon = readdoc[index]["icon"].GetString();

				auto it = article_item->clone();
				it->addClickEventListener(CC_CALLBACK_1(GUIUserMain::onArticleBeClick, this, id));
				Text* title_label = (Text*)it->getChildByName("article_title");
				title_label->setText(title);
				Text* des_label = (Text*)it->getChildByName("article_desc");
				des_label->setText(des);
				ImageView* article_icon = (ImageView*)it->getChildByName("article_icon");
				UIMan::getInstance()->addHttpSprite(article_icon, icon);
				article_list->addChild(it);
			}
			article_list->refreshView();
		}
	}
}

void GUIUserMain::onArticleBeClick(Ref *pSender, int id)
{
	ArticleMan::getInstance()->OpenArticle(id);
}