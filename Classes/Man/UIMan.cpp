#include "UIMan.h"
#include "TaskMan.h"
#include "SceneMan.h"

UIMan* UIMan::m_pInstance = nullptr;

void UIMan::onInit()
{
	isDownLoadPicture = false;
}

void UIMan::addUI(Node* node, string name)
{

}

void UIMan::addHttpSprite(ImageView* imageView, string url)
{
	if (strncmp(url.c_str(), "http://", strlen("http://")) == 0)
	{
		spriteList.insert(pair<ImageView*, string>(imageView, url));
		auto pos = url.find_last_of("/");
		string image = url.substr(pos + 1, url.length() - 1);
		string path = FileUtils::getInstance()->getWritablePath() + image;
		if (FileUtils::getInstance()->isFileExist(path))
		{
			imageView->loadTexture(path);
		}
		else if (!isDownLoadPicture)
		{
			isDownLoadPicture = true;
			TaskMan::getInstance()->getHttpPicture(url);
		}
	}
	else
	{
		LOGERROR("not a http picture: %s", url.c_str());
	}
}

void UIMan::onDownloadPictureCompleted(string url, string path)
{
	map<ImageView*, string>::iterator ite, next;
	for (ite = spriteList.begin(); ite != spriteList.end();)
	{
		next = ite;
		next++;
		if (ite->second == url)
		{
			ite->first->loadTexture(path);
			spriteList.erase(ite);
		}
		ite = next;
	}
	isDownLoadPicture = false;
	if (spriteList.size() > 0)
	{
		isDownLoadPicture = true;
		TaskMan::getInstance()->getHttpPicture(spriteList.begin()->second);
	}
}