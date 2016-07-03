#pragma once

#include "cocos2d.h"
#include "network/HttpClient.h"

USING_NS_CC;

using namespace network;

class TaskRequest
{
public:
	TaskRequest();
	~TaskRequest();

	static void sendPostRequest(const char* url, const char* data, const char* tag, const ccHttpRequestCallback& callback);
};