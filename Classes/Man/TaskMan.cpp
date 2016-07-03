#include "TaskMan.h"
#include "UIMan.h"

TaskMan* TaskMan::m_pInstance = nullptr;

void TaskMan::onInit()
{
	_downloader = std::shared_ptr<network::Downloader>(new network::Downloader);
	_downloader->setErrorCallback(std::bind(&TaskMan::onDownloadPictureError, this, std::placeholders::_1));
	_downloader->setProgressCallback(std::bind(&TaskMan::onDownloadPictureProgress, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
	_downloader->setSuccessCallback(std::bind(&TaskMan::onDownloadPictureCompleted, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}
char* URL = "http://192.168.1.107:8080/diy/user_service";
void TaskMan::login(const char* name, const char* password, const ccHttpRequestCallback& callback)
{
	const char* url = URL;
	const char* tag = "LOGIN";
	char data[256];
	sprintf(data, "tag=%s&name=%s&password=%s", tag, name, password);
	TaskRequest::sendPostRequest(url, data, tag, callback);
}

void TaskMan::preLogin(const char* name, const char* password, const ccHttpRequestCallback& callback)
{
	const char* url = URL;
	const char* tag = "PRE_LOGIN";
	char data[256];
	sprintf(data, "tag=%s&name=%s&password=%s", tag, name, password);
	TaskRequest::sendPostRequest(url, data, tag, callback);
}

void TaskMan::registerUser(const char* name, const char* password, const ccHttpRequestCallback& callback)
{
	const char* url = URL;
	const char* tag = "REGISTER";
	char data[256];
	sprintf(data, "tag=%s&name=%s&password=%s", tag, name, password);
	TaskRequest::sendPostRequest(url, data, tag, callback);
}

void TaskMan::getUserArticles(const char* name, const ccHttpRequestCallback& callback)
{
	const char* url = URL;
	const char* tag = "GET_USER_ARTICLES";
	char data[256];
	sprintf(data, "tag=%s&name=%s", tag, name);
	TaskRequest::sendPostRequest(url, data, tag, callback);
}

void TaskMan::getHttpPicture(string url)
{
	if (_downloader)
	{
		auto pos = url.find_last_of("/");
		string imageName = url.substr(pos + 1, url.length() - 1);
		std::string path = FileUtils::getInstance()->getWritablePath() + imageName;
		std::string remote = url;
		_downloader->downloadAsync(remote, path, imageName);
	}
}

std::vector<std::string> split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;//扩展字符串以方便操作  
	int size = str.size();

	for (int i = 0; i<size; i++)
	{
		pos = str.find(pattern, i);
		if (pos<size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

void TaskMan::onDownloadPictureError(const cocos2d::network::Downloader::Error& error)
{

}
void TaskMan::onDownloadPictureProgress(double totalToDownload, double nowDownloaded, const std::string& url, const std::string& customId)
{

}

void TaskMan::onDownloadPictureCompleted(const std::string& url, const std::string& path, const std::string& customId)
{
	UIMan::getInstance()->onDownloadPictureCompleted(url, path);
}