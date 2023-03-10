#include "LST.h"
SLTNode* BuyNode(SLData x)//����һ�����
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
SLTNode* SLTinit()//��ʼ��������һ������ͷ�ڱ�������
{
	SLTNode* phead = BuyNode(-1);//ͷ�ڱ�
	phead->next = phead;
	phead->prev = phead;
	return phead;//��ʼ���������������ͷ�ڱ�������
}
void SLTpushBack(SLTNode* phead,SLData x)//β��
{
	//assert(phead);//phead������ΪNULL��������Ҫ�����ж�һ�£����Ϊ���򴫴�
	//SLTNode* newnode = BuyNode(x);
	//SLTNode* tail = phead->prev;//��β
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
void SLTpopBack(SLTNode* phead)//βɾ
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
void SLTpushFront(SLTNode* phead, SLData x)//ͷ��
{
	//�����ַ�����һ���ǲ����������˳�򣬱����ȴӺ��濪ʼ����
	//��Ϊ�����ǰ��������ô��һ������λ�þͺ������ҵ��ˣ�����һ��ʼλ����ͷ�ڱ�ʱ
	/*assert(phead);
	SLTNode* newnode = BuyNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;*/
	//�ڶ����������һ������λ�ü�¼����Ϊfisrt��˳������������
	//SLTNode* fisrt = phead->next;//����һ������¼����
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = fisrt;
	//fisrt->prev = newnode;
	SLTInsert(phead->next, x);
}
void SLTpopFront(SLTNode* phead)//ͷɾ
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
void SLTInsert(SLTNode* pos, SLData x)//��posλ��ǰ�����
{
	//����ֻҪ��סpos���ǰһ�����ĵ�ַ�ͺܺø���
	//˫��pos��prev����ǰһ�����ĵ�ַ
	assert(pos);
	SLTNode* newnode = BuyNode(x);
	SLTNode* Prevpos = pos->prev;
	//Prev  newnode  pos
	Prevpos->next = newnode;
	newnode->prev = Prevpos;
	newnode->next = pos;
	pos->prev = newnode;
	//���ǿ��Է�����insert�����������posλ��ǰ����룬���ǿ��Ը�����������ͷ���β����
	//ͷ���Ǿ����ڵ�һ�����֮ǰ���룬Ҳ������posΪ��һ�����λ��Ҳ����phead->next
	//β��Ҳ������pheadǰ����뼴�ɣ��Ǿ���pos=phead
}