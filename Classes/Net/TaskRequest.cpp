#include "TaskRequest.h"
#include <thread>

TaskRequest::TaskRequest()
{
}


TaskRequest::~TaskRequest()
{
}

void TaskRequest::sendPostRequest(const char* url, const char* data, const char* tag, const ccHttpRequestCallback& callback)
{

	HttpRequest* request = new (std::nothrow) HttpRequest();
	request->setUrl(url);
	request->setRequestType(HttpRequest::Type::POST);
	request->setResponseCallback(callback);

	request->setRequestData(data, strlen(data));
	request->setTag(tag);
	HttpClient::getInstance()->send(request);
	request->release();
}