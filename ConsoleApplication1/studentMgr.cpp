#include "stdafx.h"

C_STUDENTMGR::C_STUDENTMGR() :
	m_mapStudentData()
{
}

bool C_STUDENTMGR::addStudent(const char * pName, const char * pAdd, int nPhone)
{
	std::map<std::string, S_STUDENT*>::iterator iter
		= m_mapStudentData.find(pName);

	if (iter != m_mapStudentData.end())
		return false;

	S_STUDENT * pNewStudent = new S_STUDENT{};
	pNewStudent->strName = pName;
	pNewStudent->strAdd = pAdd;
	pNewStudent->nPhone = nPhone;

	m_mapStudentData.insert(iter,
		std::map<std::string, S_STUDENT*>::value_type(pNewStudent->strName, pNewStudent));

	return true;
}

const C_STUDENTMGR::S_STUDENT * C_STUDENTMGR::findStudent(const char * pName)
{
	std::map<std::string, S_STUDENT*>::iterator iter
		= m_mapStudentData.find(pName);

	if (iter == m_mapStudentData.end())
		return nullptr;

	return iter->second;
}

void C_STUDENTMGR::deleteStudent(const char * pName)
{
	std::map<std::string, S_STUDENT*>::iterator iter
		= m_mapStudentData.find(pName);

	delete iter->second;
	iter->second = nullptr;
	m_mapStudentData.erase(iter);
}

void C_STUDENTMGR::release()
{
	std::map<std::string, S_STUDENT*>::iterator iter = m_mapStudentData.begin();

	while (iter != m_mapStudentData.end())
	{
		delete iter->second;
		iter->second = nullptr;
		iter = m_mapStudentData.erase(iter);

	}


}
