#include "ListHash.h"

TListHashTable::TListHashTable(int Size) : THashTable()
{
	pList = new std::list<TRecord>[Size];
	TabSize = Size;
	CurrList = 0;
}

TListHashTable::~TListHashTable()
{
	delete[]pList;
}

bool TListHashTable::IsFull() const
{
	return false;
}

bool TListHashTable::FindRecord(TKey k)
{
	bool res = false;
	CurrList = HashFunc(k) % TabSize;
	for (CurrI = pList[CurrList].begin(); CurrI != pList[CurrList].end(); CurrI++)
	{
		Efficiency++;
		if (CurrI->GetKey() == k)
		{
			res = true;
			break;
		}
	}
	return res;
}

int TListHashTable::InsRecord(TKey k, TValue v)
{
	if (IsFull())
	{
		return TadFull;
	}
	else
	{
		bool tmp = FindRecord(k);
		if (tmp)
		{
			return DuplRec;
		}
		else
		{
			pList[CurrList].push_front(TRecord(k, v));
			CurrI--;
			DataCount++;
			return TabOk;
		}
	}
}

int TListHashTable::DelRecord(TKey k)
{
	if (IsEmpty())
	{
		return TabEmpty;
	}
	else
	{
		bool tmp = FindRecord(k);
		if (!tmp)
		{
			return TabNoRec;
		}
		else
		{
			pList[CurrList].erase(CurrI);
			DataCount--;
			return TabOk;
		}
	}
}

int TListHashTable::Reset()
{
	CurrList = 0;
	while (pList[CurrList].begin() == pList[CurrList].end())
	{
		CurrList++;
	}
	CurrI = pList[CurrList].begin();
	return IsTabEnd();
}

int TListHashTable::IsTabEnd() const
{
	return ((CurrList >= TabSize - 1) && (CurrI == pList[CurrList].end()));
}

int TListHashTable::GoNext()
{
	CurrI++;
	while (CurrI == pList[CurrList].end() && (CurrList < TabSize-1))
	{
		CurrList++;
		CurrI = pList[CurrList].begin();
	}
	return IsTabEnd();
}

TKey TListHashTable::GetKey()const
{
	return CurrI->GetKey();
}

TValue TListHashTable::GetVal() const
{
	return CurrI->GetVal();
}
