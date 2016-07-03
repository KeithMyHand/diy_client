#pragma once
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace std;
using namespace cocos2d;
using namespace ui;
class ArticleMan
{
private:
	static ArticleMan* m_pInstance;
public:
	static ArticleMan* getInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new ArticleMan();
		return m_pInstance;
	}
	~ArticleMan();
	void onInit();

public:
	void OpenArticle(int id);
};