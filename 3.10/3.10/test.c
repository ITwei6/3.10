#include "LST.h"
void test1()
{
	SLTNode* plist=SLTinit();//初始化函数，生成一个带有头哨兵的链表
	SLTpushBack(plist,1);
	SLTpushBack(plist,2);
	SLTpushBack(plist,3);
	SLTpushBack(plist,4);
	SLTPrint(plist);
	SLTpopBack(plist);
	SLTpopBack(plist);
	printf("\n");
	SLTPrint(plist);

}
void test2()
{
	SLTNode* plist = SLTinit();//初始化函数，生成一个带有头哨兵的链表
	SLTpushFront(plist, 1);
	SLTpushFront(plist, 2);
	SLTpushFront(plist, 3);
	SLTpushFront(plist, 4);
	SLTPrint(plist);
	printf("\n");
	/*SLTpopFront(plist);
	SLTpopFront(plist);
	SLTPrint(plist);*/
}
int main()
{
	test1();
	/*test2();*/
	return 0;
}