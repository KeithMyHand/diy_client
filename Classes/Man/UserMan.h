#pragma once
#include "../Data/UserData.h"

class UserMan
{
private:
	static UserMan* m_pInstance;
public:
	static UserMan* getInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new UserMan();
		return m_pInstance;
	}
	~UserMan();
	void onInit();

private:
	UserData* userData = nullptr;
public:
	void setUserData(char* jsonData);
	void setUserName(char* name);
	void setUserSign(char* sign);
	void setUserLevel(int level);
	char* getUserName();
	char* getUserSign();
	int getUserLevel();
};