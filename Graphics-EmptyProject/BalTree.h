#pragma once
#include"TTreeTable.h"
#define HeighOk 0
#define HeighInc 1
#define HeighDel -1

class TBalanceTree : public TTreeTable
{
protected:
	int InsBalanceTree(TTreeNode* &pNode, TKey k, TValue v);  //�������� ������ � �������������
	int LeftTreeBalancing(TTreeNode* &pNode); //������������ ������ ���������
	int RightTreeBalancing(TTreeNode* &pNode); //������������ ������� ���������
	int DelBalanceTree(TTreeNode* &pNode, TKey k);
	int DelMin(TTreeNode* &pNode); //���������� ���� � ����������� ����� �� ����������
	TTreeNode* FindMin(TTreeNode* pNode);
public:
	TBalanceTree() :TTreeTable() {}

	virtual int InsRecord(TKey k, TValue v);
	virtual int DelRecord(TKey k);
};