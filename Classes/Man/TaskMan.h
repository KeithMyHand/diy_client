#pragma once
#include "../Net/TaskRequest.h"
#include "network/CCDownloader.h"

using namespace std;

class TaskMan
{
private:
	static TaskMan* m_pInstance;
public:
	~TaskMan();
	static TaskMan* getInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new TaskMan();
		return m_pInstance;
	}
	void onInit();
	void login(const char* name, const char* password, const ccHttpRequestCallback& callback);
	void preLogin(const char* name, const char* password, const ccHttpRequestCallback& callback);
	void registerUser(const char* name, const char* password, const ccHttpRequestCallback& callback);
	void getUserArticles(const char* name, const ccHttpRequestCallback& callback);
	void getHttpPicture(string url);

private:
	std::shared_ptr<cocos2d::network::Downloader> _downloader;
	void onDownloadPictureError(const cocos2d::network::Downloader::Error& error);
	void onDownloadPictureProgress(double totalToDownload, double nowDownloaded, const std::string& url, const std::string& customId);
	void onDownloadPictureCompleted(const std::string& url, const std::string& path, const std::string& customId);
};