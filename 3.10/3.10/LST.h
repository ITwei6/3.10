#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int SLData;//因为不知道要传入的数据是何类型，先定义为int类型，后面有需要再改。
typedef struct SLTNode//创建一个双向链表结构体
{
	struct SLTNode* next;//指向下一个结点的地址
	struct SLTNode* prev;//指向前一个结点的地址
	SLData data;//结点中的数据
}SLTNode;
//初始化循环链表
SLTNode* SLTinit();
//生成一个新结点
SLTNode* BuyNode(SLData x);
//循环链表尾插
void SLTpushBack(SLTNode*phead,SLData x);
//循环链表打印
void SLTPrint(SLTNode* phead);
//判断是否为空--还剩下一个哨兵头
bool SLTEmpty(SLTNode* phead);
//循环链表尾删
void SLTpopBack(SLTNode* phead);
//循环链表头插
void SLTpushFront(SLTNode* phead,SLData x);
//循环链表头删
void SLTpopFront(SLTNode* phead);
//在pos位置前面插入一个结点
void SLTInsert(SLTNode* pos, SLData x);
//在pos位置删除一个结点
void SLTErase(SLTNode* pos);
//销毁循环链表
void SLTDestroy(SLTNode* phead);
