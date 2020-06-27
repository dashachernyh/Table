#pragma once
#include"Record.h"
#define BalOk 0
#define BalLeft -1
#define BalRight 1

class TTreeNode :public TRecord //потомок класса
{
protected:
	TTreeNode *pLeft, *pRight;  //указатели на правое и левое поддеревья
	int Balance;   //(-1,0,1)
public:
	TTreeNode() { pLeft = pRight = NULL; Balance = BalOk; }  //конструктор по умолчанию
	TTreeNode(TKey k, TValue v, TTreeNode *pL = NULL, TTreeNode *pR = NULL, int bal = BalOk) :TRecord(k, v), pLeft(pL), pRight(pR), Balance(bal) {} //конструктор инициализации
	//доступ
	TTreeNode* GetLeft() const { return pLeft; }   //указатель на  левое поддерево
	TTreeNode* GetRight() const { return pRight; } //указатель на правое поддерево

	int GetBalance(void) const { return Balance; }
	void SetBalance(int bal) { Balance = bal; }

	//дружественные классы
	friend class TTreeTable;
	friend class TBalanceTree;
};