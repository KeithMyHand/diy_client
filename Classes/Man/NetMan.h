#pragma once
#include <thread>
#include <map>
#include "..\Net\TaskData.h"

using namespace std;

class NetMan
{
private:
	static NetMan* m_pInstance;
public:
	~NetMan();
	static NetMan* getInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new NetMan();
		return m_pInstance;
	}
	void onInit();

private:
	list<TaskData*> tasks;
	
public:
	void addTask(TaskData* task);
	void removeTask(TaskData* task);
};