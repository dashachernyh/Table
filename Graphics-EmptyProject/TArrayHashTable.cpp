#include"TArrayHashTable.h"

TArrayHashTable::TArrayHashTable(int size, int step):TabSize(size),HashStep(step)
{
	MasRec = new TRecord[TabSize];
	Empty = TRecord(-1);
	Mark = TRecord(-2);
	for (int i = 0; i < TabSize; i++)
	{
		MasRec[i] = Empty;
	}
}

TArrayHashTable::~TArrayHashTable()
{
	delete[]MasRec;
}

bool TArrayHashTable::FindRecord(TKey k)
{
	bool res = false;
	FreePos = -1;
	CurrPos = HashFunc(k) % TabSize;
	for (int i = 0; i < TabSize; i++)
	{
		Efficiency++;
		if (MasRec[CurrPos] == Empty)  //свободная сторка- никогда не была занята
			break;
		else
			if (MasRec[CurrPos] == Mark)  //пустая строка-удалили запись. запоминаем первую
			{
				if (FreePos == -1)
					FreePos = CurrPos;
			}
			else
				if (MasRec[CurrPos].Key == k)
				{
					res = true;
					break;
				}
		CurrPos = GetNextPos(CurrPos);
	}
	return res;
}

int TArrayHashTable::InsRecord(TKey k, TValue v)
{
	if (IsFull())
	{
		return TadFull;
	}
	else
	{
		bool res = FindRecord(k);
		if (res)
		{
			return DuplRec;
		}
		else
		{
			if (FreePos != -1)
			{
				CurrPos = FreePos;
			}
			MasRec[CurrPos] = TRecord(k, v);
			DataCount++;
			return TabOk;
		}
	}
}

int TArrayHashTable::DelRecord(TKey k)
{
	if (IsEmpty())
	{
		return TabEmpty;
	}
	else
	{
		bool res = FindRecord(k);
		if (!res)
		{
			return TabNoRec;
		}
		else
		{
			MasRec[CurrPos] = Mark;
			DataCount--;
			return TabOk;
		}
	}
}

//итерирование

int TArrayHashTable::Reset()
{
	CurrPos = 0;
	while (CurrPos < TabSize)
	{
		if (MasRec[CurrPos] != Empty && MasRec[CurrPos] != Mark) break;
		else CurrPos++;
	}
	return IsTabEnd();
}

int TArrayHashTable::IsTabEnd() const
{
	return (CurrPos >= TabSize);
}

int TArrayHashTable::GoNext()
{
	CurrPos++;
	while (CurrPos < TabSize)
	{
		if (MasRec[CurrPos] != Empty && MasRec[CurrPos] != Mark) break;
		else CurrPos++;
	}
	return IsTabEnd();
}

TKey TArrayHashTable::GetKey(void) const
{
	return MasRec[CurrPos].GetKey();
}
TValue TArrayHashTable::GetVal(void) const
{
	return MasRec[CurrPos].GetVal();
}