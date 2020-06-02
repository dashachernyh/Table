#pragma once
#include"Record.h"

class TTreeNode :public TRecord
{
protected:
	TTreeNode *pLeft, *pRight;
public:
	TTreeNode() { pLeft = pRight = NULL; }
	TTreeNode(TKey k, TValue v, TTreeNode *pL=NULL, TTreeNode *pR=NULL):TRecord(k,v),pLeft(pL),pRight(pR){}
	TTreeNode* GetLeft() const { return pLeft; }
	TTreeNode* GetRight() const { return pRight; }

	friend class TTreeTable;
};