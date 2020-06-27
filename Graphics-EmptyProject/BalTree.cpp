
#include"BalTree.h"

int TBalanceTree::InsBalanceTree(TTreeNode* &pNode, TKey k, TValue v)
{
	Efficiency++;
	int HeighIndex = HeighOk;
	if (pNode == NULL)
	{
		//вставка вершины
		pNode = new TTreeNode(k, v);
		HeighIndex = HeighInc;
		DataCount++;
	}
	else if (k < pNode->GetKey())
		{
			if (InsBalanceTree(pNode->pLeft, k, v) == HeighInc)  //после вставки увел высота левого поддерева
				HeighIndex = LeftTreeBalancing(pNode);
		}

		else if (k > pNode->GetKey())
		{
			if (InsBalanceTree(pNode->pRight, k, v) == HeighInc)  //после вставки увел высота правого поддерва
				HeighIndex = RightTreeBalancing(pNode);
		}

		else
		{
			//совпадение ключей
			HeighIndex = HeighOk;
		}
	return HeighIndex;
}

//балансировка после вставки в левое поддерево
int TBalanceTree::LeftTreeBalancing(TTreeNode* &pNode)
{
	Efficiency++;
	int HeighIndex = HeighOk;
	switch (pNode->GetBalance())
	{
	case BalRight: pNode->SetBalance(BalOk);
		HeighIndex = HeighOk; break;
	case BalOk: pNode->SetBalance(BalLeft);
		HeighIndex = HeighInc; break;
	case BalLeft:
		TTreeNode *p1, *p2;
		p1 = pNode->pLeft;
		if (p1->GetBalance() == BalLeft)
		{
			pNode->pLeft = p1->pRight;
			p1->pRight = pNode;
			pNode->SetBalance(BalOk);
			pNode = p1;
		}
		else
		{
			p2 = p1->pRight;
			p1->pRight = p2->pLeft;
			p2->pLeft = p1;
			pNode->pLeft = p2->pRight;
			p2->pRight = pNode;
			if (p2->GetBalance() == BalLeft) pNode->SetBalance(BalRight);
			else pNode->SetBalance(BalOk);
			if (p2->GetBalance() == BalRight) p1->SetBalance(BalLeft);
			else p1->SetBalance(BalOk);
			pNode = p2;
		}
		pNode->SetBalance(BalOk);
		HeighIndex = HeighOk;
	}
	return HeighIndex;
}

//балансировка после вставки в правое поддерево
int TBalanceTree::RightTreeBalancing(TTreeNode* &pNode)
{
	Efficiency++;
	int HeighIndex = HeighOk;
	switch (pNode->GetBalance())
	{
	case BalLeft: pNode->SetBalance(BalOk);
		 HeighIndex = HeighOk; break;
	case BalOk: pNode->SetBalance(BalRight);
		 HeighIndex = HeighInc; break;
	case BalRight:
		TTreeNode *p1, *p2;
		p1 = pNode->pRight;
		if (p1->GetBalance() == BalRight)
		{
			pNode->pRight = p1->pLeft;
			p1->pLeft = pNode;
			pNode->SetBalance(BalOk);
			pNode = p1;
		}
		else
		{
			p2 = p1->pLeft;
			p1->pLeft = p2->pRight;
			p2->pRight = p1;
			pNode->pRight = p2->pLeft;
			p2->pLeft = pNode;
			if (p2->GetBalance() == BalRight) pNode->SetBalance(BalLeft);
			else pNode->SetBalance(BalOk);
			if (p2->GetBalance() == BalLeft) p1->SetBalance(BalRight);
			else p1->SetBalance(BalOk);
			pNode = p2;
		}
		pNode->SetBalance(BalOk);
		HeighIndex = HeighOk;
	}
	return HeighIndex;
}

int TBalanceTree::InsRecord(TKey k, TValue v)
{
	if (IsFull())
	{
		return TadFull;
	}
	else
	{
		InsBalanceTree(pRoot, k, v);
		return TabOk;
	}
}

int TBalanceTree::DelRecord(TKey k)
{
	if (IsEmpty())
	{
		return TabEmpty;
	}
	else
	{
		DelBalanceTree(pRoot, k);
		return TabOk;
	}
}

int TBalanceTree::DelBalanceTree(TTreeNode* &pNode, TKey k)
{
	Efficiency++;
	int HeighIndex = HeighOk;
	//ключ отсутсвует
	if (pNode == NULL) HeighIndex = HeighOk;
	else if (k < pNode->GetKey())
		{
			if (DelBalanceTree(pNode->pLeft, k) == HeighDel)  //после удаления уменьш высота левого поддерева
				HeighIndex = LeftTreeBalancing(pNode);
		}

		else if (k > pNode->GetKey())
		{
			if (DelBalanceTree(pNode->pRight, k) == HeighDel)  //после удаления уменьш высота правого поддерва
				HeighIndex = RightTreeBalancing(pNode);
		}

		else
		{
			TTreeNode* p1 = pNode->pLeft, *p2 = pNode->pRight;
			if (p2)
			{
				TTreeNode* min = FindMin(p2);
				HeighIndex = DelMin(p2);
				min->pRight = p2;
				min->pLeft = p1;
				pNode = min;
			}
			else pNode = p1;
			
			DataCount--;
		}
	return HeighIndex;
}

int TBalanceTree::DelMin(TTreeNode* &pNode)
{
	int HeighIndex = HeighOk;
	if (pNode->pLeft == NULL)
	{
		HeighIndex = HeighDel;
		pNode = pNode->pRight;
		return HeighIndex;
	}
	else
	{
		HeighIndex = DelMin(pNode->pLeft);
		return HeighIndex;
	}
}

TTreeNode* TBalanceTree::FindMin(TTreeNode* pNode)
{
	return pNode->pLeft ? FindMin(pNode->pLeft): pNode;
}
