#include "TaskData.h"

TaskData::TaskData()
{
}


TaskData::~TaskData()
{
}

const char* TaskData::getUrl()
{
	return url;
}

const char* TaskData::getData()
{
	return data;
}

const char* TaskData::getTag()
{
	return tag;
}

const ccHttpRequestCallback* TaskData::getCallback()
{
	return callback;
}

void TaskData::setUrl(const char* _url)
{
	url = _url;
}

void TaskData::setData(const char* _data)
{
	data = _data;
}

void TaskData::setTag(const char* _tag)
{
	tag = _tag;
}

void TaskData::setCallback(const ccHttpRequestCallback& _callback)
{
	callback = &_callback;
}