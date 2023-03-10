#include "LST.h"
SLTNode* BuyNode(SLData x)//生成一个结点
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		perror("malloc");
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
SLTNode* SLTinit()//初始化，生成一个带有头哨兵的链表
{
	SLTNode* phead = BuyNode(-1);//头哨兵
	phead->next = phead;
	phead->prev = phead;
	return phead;//初始化，返回这个带有头哨兵的链表；
}
void SLTpushBack(SLTNode* phead,SLData x)//尾插
{
	//assert(phead);//phead不可能为NULL，所以需要声明判断一下，如果为空则传错
	//SLTNode* newnode = BuyNode(x);
	//SLTNode* tail = phead->prev;//找尾
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	SLTInsert(phead, x);
}
void SLTPrint(SLTNode* phead)
{
	assert(phead);
	SLTNode* cur = phead->next;
	while (cur!=phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
}
bool SLTEmpty(SLTNode* phead)
{
	assert(phead);
	if (phead->next == phead)
		return true;
	else
		return false;
}
void SLTpopBack(SLTNode* phead)//尾删
{
	assert(phead);
	assert(!SLTEmpty(phead));
	SLTNode* tail = phead->prev;
	SLTNode* Prevtail = tail->prev;
	Prevtail->next = phead;
	phead->prev = Prevtail;
	free(tail);
	tail = NULL;
}
void SLTpushFront(SLTNode* phead, SLData x)//头插
{
	//有两种方法，一种是不能随意更改顺序，必须先从后面开始链接
	//因为如果从前面链接那么第一个结点的位置就很难再找到了，就是一开始位置是头哨兵时
	/*assert(phead);
	SLTNode* newnode = BuyNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;*/
	//第二种如果将第一个结点的位置记录下来为fisrt那顺序就随意更改了
	//SLTNode* fisrt = phead->next;//将第一个结点记录下来
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = fisrt;
	//fisrt->prev = newnode;
	SLTInsert(phead->next, x);
}
void SLTpopFront(SLTNode* phead)//头删
{
	assert(phead);
	assert(!SLTEmpty(phead));
	SLTNode* cur = phead->next;
	SLTNode* Nextcur = cur->next;
	phead->next = Nextcur;
	Nextcur->prev = phead;
	free(cur);
	cur = NULL;
}
void SLTInsert(SLTNode* pos, SLData x)//在pos位置前面插入
{
	//我们只要记住pos结点前一个结点的地址就很好搞了
	//双向pos的prev就是前一个结点的地址
	assert(pos);
	SLTNode* newnode = BuyNode(x);
	SLTNode* Prevpos = pos->prev;
	//Prev  newnode  pos
	Prevpos->next = newnode;
	newnode->prev = Prevpos;
	newnode->next = pos;
	pos->prev = newnode;
	//我们可以发现在insert这个函数是在pos位置前面插入，我们可以复用它来代替头插和尾插了
	//头插那就是在第一个结点之前插入，也就是让pos为第一个结点位置也就是phead->next
	//尾插也就是在phead前面插入即可，那就让pos=phead
}