#include"TTreeTable.h"

//когда закончится памать - true
bool TTreeTable::IsFull()const
{
	return false;
}

bool TTreeTable::FindRecord(TKey k)
{
	pPrev = NULL;
	pCurr = pRoot;
	while (pCurr != NULL)
	{
		Efficiency++;
		if (pCurr->Key == k) break;
		pPrev = pCurr;
		if (pCurr->Key < k) pCurr = pCurr->pRight;
		else pCurr = pCurr->pLeft;
	}
	if (pCurr != NULL)
	{
		return true;
	}
	else
	{
		pCurr = pPrev;  //указывает на вершину, к которой может быть подсоединен узел
		return false;
	}
}

int TTreeTable::InsRecord(TKey k, TValue v)
{
	if (IsFull()) return TadFull;
	else
	{
		if (FindRecord(k)==true)
		{
			return DuplRec;
		}
		else
		{
			TTreeNode *tmp = new TTreeNode(k, v);
			if (pRoot == NULL)
			{
				pRoot = tmp;
			}
			else
			{
				if (pCurr->Key < k)
				{
					pCurr->pRight = tmp;
				}
				else
				{
					pCurr->pLeft = tmp;
				}
			}
			Efficiency++;
			DataCount++;
			return TabOk;
		}	
	}
}

int TTreeTable::DelRecord(TKey k)
{
	if (FindRecord(k) == false) return TabNoRec;
	else
	{
		TTreeNode *pNode = pCurr;
		if (pNode->pRight == NULL)  //нет потомков с права
		{
			if (pPrev == NULL)  //текущий указывает на корень
			{
				pRoot = pNode->pLeft;
			}
			else
			{
				if (pPrev->pRight == pNode)
				{
					pPrev->pRight = pNode->pLeft;
				}
				else
				{
					pPrev->pLeft = pNode->pLeft;
				}
			}
			Efficiency++;
		}
		else if (pNode->pLeft == NULL)   //один потомок справа (слева нет)
		{
				if (pPrev == NULL)
				{
					pRoot = pNode->pRight;
				}
				else
				{
					if (pPrev->pRight == pNode)
					{
						pPrev->pRight = pNode->pRight;
					}
					else
					{
						pPrev->pLeft = pNode->pRight;
					}
				}
		}
		else     //два потомка,поиск крайнего с права у левого потомка
		{
			TTreeNode *pN = pNode->pLeft;
			pPrev = pNode;
			while (pN->pRight != NULL)
			{
				pPrev = pN;
				pN = pN->pRight;
				Efficiency++;
			}
			//вместо pNode удаляется pN
			pNode->Key = pN->Key;
			pNode->Val = pN->Val;
			if (pPrev->pRight == pN)
			{
				pPrev->pRight = pN->pLeft;
			}
			else
			{
				pPrev->pLeft = pN->pLeft;
			}
			pNode = pN;
			Efficiency++;
		}
		delete pNode;
		DataCount--;
		return TabOk;
	}
}

void TTreeTable::DeleteTreeTab(TTreeNode *pNode)
{
	if (pNode != NULL)
	{
		DeleteTreeTab(pNode->pRight);
		DeleteTreeTab(pNode->pLeft);
		delete pNode;
	}
}

int TTreeTable::Reset()
{
	TTreeNode *pNode =pCurr= pRoot;   //установили на первую запись
	while (!Stack.empty()) Stack.pop();  //очистка стека
	CurrPos = 0;
	while (pNode != NULL)
	{
		Stack.push(pNode);
		pCurr = pNode;
		pNode = pNode->pLeft;
	}
	return IsTabEnd();
}

int TTreeTable::IsTabEnd() const
{
	return CurrPos >= DataCount;
}

int TTreeTable::GoNext()
{
	if (!IsTabEnd() && pCurr != NULL)
	{
		TTreeNode *pNode =pCurr= pCurr->pRight;  //переход в право
		Stack.pop();
		while (pNode != NULL)
		{
			//переход к крайней левой вершине
			Stack.push(pNode);
			pCurr = pNode;
			pNode = pNode->pLeft;
		}
		//если нет правого потомка
		if (pCurr == NULL && !Stack.empty())
		{
			pCurr=Stack.top();
		}
		CurrPos++;
	}
	return IsTabEnd();
}

TKey TTreeTable::GetKey()const
{
	if (pCurr != NULL)
	{
		return pCurr->Key;
	}
	else throw NULL;
}
TValue TTreeTable::GetVal()const
{
	if (pCurr != NULL)
	{
		return pCurr->Val;
	}
	else throw NULL;
}

//печать

void TTreeTable::PrintTable(std::ostream& os)
{
	os << "Printing of table" << std::endl;
	level = 0;
	PrintTreeTable(os, pRoot);
}

void TTreeTable::PrintTreeTable(std::ostream &os, TTreeNode *pNode)
{
	if (pNode != NULL)
	{
		for (int i = 0; i < level; i++)
			os <<" ";
		os << pNode->Key << std::endl;
		level++;
		PrintTreeTable(os, pNode->pRight);
		PrintTreeTable(os, pNode->pLeft);
		level--;
	}
}

