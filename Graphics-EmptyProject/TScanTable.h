#pragma once
#include"TArrayTable.h"

class TScanTable :public TArrayTable
{
public:
	TScanTable(int size = MaxSize) :TArrayTable(size) {}
	virtual bool FindRecord(TKey k);
	virtual int InsRecord(TKey k, TValue v);
	virtual int DelRecord(TKey k);
};