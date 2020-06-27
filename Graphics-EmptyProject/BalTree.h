#pragma once
#include"TTreeTable.h"
#define HeighOk 0
#define HeighInc 1
#define HeighDel -1

class TBalanceTree : public TTreeTable
{
protected:
	int InsBalanceTree(TTreeNode* &pNode, TKey k, TValue v);  //вставить запись с балансировкой
	int LeftTreeBalancing(TTreeNode* &pNode); //балансировка левого поддерева
	int RightTreeBalancing(TTreeNode* &pNode); //балансировка правого подддерва
	int DelBalanceTree(TTreeNode* &pNode, TKey k);
	int DelMin(TTreeNode* &pNode); //исключение узла с минимальным узлом из подддереве
	TTreeNode* FindMin(TTreeNode* pNode);
public:
	TBalanceTree() :TTreeTable() {}

	virtual int InsRecord(TKey k, TValue v);
	virtual int DelRecord(TKey k);
};