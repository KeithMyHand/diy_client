#pragma once
#include "cocos2d.h"
#include "../Net/TaskRequest.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace std;
using namespace ui;
class UIMan
{
private:
	static UIMan* m_pInstance;
public:
	~UIMan();
	static UIMan* getInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new UIMan();
		return m_pInstance;
	}
	void onInit();
	void addUI(Node* node, string name);

private:
	map<ImageView*, string> spriteList;
	bool isDownLoadPicture;
public:
	void addHttpSprite(ImageView* imageView, string url);

	void onDownloadPictureCompleted(string url, string path);
};