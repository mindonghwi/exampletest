// ConsoleApplication1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	C_STUDENTMGR cStundetMgr;

	cStundetMgr.addStudent("ö��", "����", 435435);
	cStundetMgr.addStudent("�μ�", "����", 657455);
	cStundetMgr.addStudent("����", "â��", 356834);
	cStundetMgr.addStudent("�ٵ���", "����", 324556);

	const C_STUDENTMGR::S_STUDENT *pStudent = cStundetMgr.findStudent("�μ�");
	if (!pStudent)
		printf("����\n");
	else 
		printf("%s , %s , %d\n" , pStudent->strName.data() , pStudent->strAdd.data() , pStudent->nPhone);

	cStundetMgr.deleteStudent("����");

	const C_STUDENTMGR::S_STUDENT *pStudent1 = cStundetMgr.findStudent("����");
	if (!pStudent1)
		printf("����\n");
	else
		printf("%s , %s , %d\n", pStudent1->strName.data(), pStudent1->strAdd.data(), pStudent1->nPhone);


	cStundetMgr.release();
    return 0;
}

