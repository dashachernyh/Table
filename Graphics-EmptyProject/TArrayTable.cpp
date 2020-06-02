#include<iostream>
using namespace std;
#include "TArrayTable.h"


int TArrayTable:: Reset(void)
{

		pCurr = 0;
		return (!IsTabEnd());
}

int TArrayTable::IsTabEnd(void) const
{
	return (pCurr>=DataCount);
}

int TArrayTable::GoNext(void)
{
	if (!IsTabEnd())
	   pCurr++;
	return !IsTabEnd();
}

int TArrayTable::SetCurr(int pos)
{
		if (pos >= 0 && pos < DataCount)
			pCurr = pos;
		return (!IsTabEnd());
	
}

TKey TArrayTable::GetKey(PosData m)const
{
	return MasRec[pCurr].GetKey();
}

TValue TArrayTable::GetVal(PosData m) const
{
	if (pCurr<0 || pCurr>TabSize) return "wrong_pos";
	if (pCurr > DataCount && pCurr <= TabSize)
	{
		TValue v = "undef";
		MasRec[pCurr].SetVal(v);
		return MasRec[pCurr].GetVal();
	}
	else return MasRec[pCurr].GetVal();
}