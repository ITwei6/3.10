#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int SLData;//��Ϊ��֪��Ҫ����������Ǻ����ͣ��ȶ���Ϊint���ͣ���������Ҫ�ٸġ�
typedef struct SLTNode//����һ��˫������ṹ��
{
	struct SLTNode* next;//ָ����һ�����ĵ�ַ
	struct SLTNode* prev;//ָ��ǰһ�����ĵ�ַ
	SLData data;//����е�����
}SLTNode;
//��ʼ��ѭ������
SLTNode* SLTinit();
//����һ���½��
SLTNode* BuyNode(SLData x);
//ѭ������β��
void SLTpushBack(SLTNode*phead,SLData x);
//ѭ�������ӡ
void SLTPrint(SLTNode* phead);
//�ж��Ƿ�Ϊ��--��ʣ��һ���ڱ�ͷ
bool SLTEmpty(SLTNode* phead);
//ѭ������βɾ
void SLTpopBack(SLTNode* phead);
//ѭ������ͷ��
void SLTpushFront(SLTNode* phead,SLData x);
//ѭ������ͷɾ
void SLTpopFront(SLTNode* phead);
//��posλ��ǰ�����һ�����
void SLTInsert(SLTNode* pos, SLData x);
//��posλ��ɾ��һ�����
void SLTErase(SLTNode* pos);
//����ѭ������
void SLTDestroy(SLTNode* phead);
