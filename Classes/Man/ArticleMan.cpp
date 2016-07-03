#include "ArticleMan.h"
#include "SceneMan.h"

ArticleMan* ArticleMan::m_pInstance = nullptr;

void ArticleMan::onInit()
{

}

char* ARTICLE_PATH_BASE = "http://192.168.1.107:8080/diy/articles";
void ArticleMan::OpenArticle(int id)
{
	LOGINFO("open article id: %d", id);
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::experimental::ui::WebView *_webView = cocos2d::experimental::ui::WebView::create();
	auto winSize = Director::getInstance()->getWinSize();
	_webView->setPosition(winSize / 2);
	_webView->setContentSize(winSize);
	char url[256];
	sprintf(url, "%s/article_%d/article.jsp", ARTICLE_PATH_BASE, id);
	_webView->loadURL(url);
	_webView->setScalesPageToFit(true);
	SceneMan::getInstance()->getCrrentScene()->addChild(_webView);
#endif
}