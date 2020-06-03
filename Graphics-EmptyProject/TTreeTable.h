#pragma once
#include<fstream>
#include"TTreeNode.h"
#include"TTable.h"
#include<stack>
class TTreeTable :public TTable
{
protected:
	TTreeNode *pRoot;   //указатель на корень дерева
	TTreeNode *pCurr;   //указатель на текущую вершину
	TTreeNode *pPrev;   //указаель на пред вершину
	int CurrPos;   //номер текущей вершины
	std::stack<TTreeNode*> Stack;

	int level;
	void PrintTable(std::ostream &os);
	void PrintTreeTable(std::ostream &os,TTreeNode *pNode);
	void DeleteTreeTab(TTreeNode *pNode); 
	
	
public:
	TTreeTable() :TTable() { pRoot = pCurr = NULL; CurrPos = 0; }
	~TTreeTable() { DeleteTreeTab(pRoot); }

	virtual bool IsFull()const;
	virtual int Reset(void);
	virtual int IsTabEnd(void) const;
	virtual int GoNext(void);

	virtual bool FindRecord(TKey k);
	virtual int InsRecord(TKey k, TValue v);
	virtual int DelRecord(TKey k);

	virtual TKey GetKey()const;
	virtual TValue GetVal() const;
	friend std::istream & operator >>(istream& is, TTreeTable &tab)
	{
		int data_count;
		TKey k;
		TValue v;
		std::cout<< "enter DataCount"<<std::endl;
		is >> data_count;
		std::cout << "enter Key and Value"<<std::endl;
		for (int i = 0; i < data_count; i++)
		{
			is >> k;
			is >> v;
			tab.InsRecord(k, v);
		}
		return is;
	}
	friend std::ostream & operator <<(ostream& os, TTreeTable &tab)
	{
		tab.PrintTable(os);
		return os;
	}
	void FPrintTable(string str);
};
