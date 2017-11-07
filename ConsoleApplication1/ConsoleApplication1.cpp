// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	C_STUDENTMGR cStundetMgr;

	cStundetMgr.addStudent("철수", "성남", 435435);
	cStundetMgr.addStudent("민수", "강남", 657455);
	cStundetMgr.addStudent("영희", "창동", 356834);
	cStundetMgr.addStudent("바둑이", "수유", 324556);

	const C_STUDENTMGR::S_STUDENT *pStudent = cStundetMgr.findStudent("민수");
	if (!pStudent)
		printf("없다\n");
	else 
		printf("%s , %s , %d\n" , pStudent->strName.data() , pStudent->strAdd.data() , pStudent->nPhone);

	cStundetMgr.deleteStudent("영희");

	const C_STUDENTMGR::S_STUDENT *pStudent1 = cStundetMgr.findStudent("영희");
	if (!pStudent1)
		printf("없다\n");
	else
		printf("%s , %s , %d\n", pStudent1->strName.data(), pStudent1->strAdd.data(), pStudent1->nPhone);


	cStundetMgr.release();
    return 0;
}

