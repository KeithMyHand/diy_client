#pragma once

class UserData
{
public:
	UserData();
	~UserData();

private:
	char* name = new char[32];
	char* sign = new char[64];
	int level;

public:
	char* getName();
	char* getSign();
	int getLevel();

	void setName(char* _name);
	void setSign(char* _sign);
	void setLevel(int _level);
};