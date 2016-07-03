#pragma once
#include "Net\TaskRequest.h"

class TaskData
{
public:
	TaskData();
	~TaskData();

private:
	const char* url;
	const char* data;
	const char* tag;
	const ccHttpRequestCallback* callback;
public:
	const char* getUrl();
	const char* getData();
	const char* getTag();
	const ccHttpRequestCallback* getCallback();

	void setUrl(const char* _url);
	void setData(const char* _data);
	void setTag(const char* _tag);
	void setCallback(const ccHttpRequestCallback& _callback);
};