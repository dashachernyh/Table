
#include "TScanTable.h"

bool TScanTable::FindRecord(TKey k)
{
	int i;
	for (i=0;i<DataCount;i++)
	{
		Efficiency++;
		if(k==MasRec[i].Key) break;
	}
	//Efficiency += i + 1;
	if (i < DataCount)
	{
		pCurr = i;
		return true;
	}
	else
	{
		pCurr = i ;
		return false;
	}
}

int TScanTable::InsRecord(TKey k, TValue v)
{
	if (IsFull())
	{
		return TadFull;
	}
	else
	{
		if (FindRecord(k)) return DuplRec;
		else
		{
			MasRec[pCurr] = TRecord(k, v);
			DataCount++;
			return TabOk;
		}

	}
}

int TScanTable::DelRecord(TKey k)
{
	if (IsEmpty()) return TabEmpty;
	{
		if (!FindRecord(k)) return TabNoRec;
		else
		{
			MasRec[pCurr].Key = MasRec[DataCount - 1].Key;
			MasRec[pCurr].Val = MasRec[DataCount - 1].Val;
			DataCount--;
			return TabOk;
		}
	}
}