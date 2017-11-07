#pragma once

#include<map>
#include<string>

class C_STUDENTMGR
{
public:
	struct S_STUDENT
	{
		std::string strName;
		std::string strAdd;
		int nPhone;
	};
private:
	std::map<std::string, S_STUDENT*> m_mapStudentData;

public:
	C_STUDENTMGR();
	bool addStudent(const char *pName, const char *pAdd, int nPhone);
	const S_STUDENT * findStudent(const char *pName);
	void deleteStudent(const char *pName);
	void release();
};
