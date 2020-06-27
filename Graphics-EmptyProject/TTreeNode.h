#pragma once
#include"Record.h"
#define BalOk 0
#define BalLeft -1
#define BalRight 1

class TTreeNode :public TRecord //������� ������
{
protected:
	TTreeNode *pLeft, *pRight;  //��������� �� ������ � ����� ����������
	int Balance;   //(-1,0,1)
public:
	TTreeNode() { pLeft = pRight = NULL; Balance = BalOk; }  //����������� �� ���������
	TTreeNode(TKey k, TValue v, TTreeNode *pL = NULL, TTreeNode *pR = NULL, int bal = BalOk) :TRecord(k, v), pLeft(pL), pRight(pR), Balance(bal) {} //����������� �������������
	//������
	TTreeNode* GetLeft() const { return pLeft; }   //��������� ��  ����� ���������
	TTreeNode* GetRight() const { return pRight; } //��������� �� ������ ���������

	int GetBalance(void) const { return Balance; }
	void SetBalance(int bal) { Balance = bal; }

	//������������� ������
	friend class TTreeTable;
	friend class TBalanceTree;
};