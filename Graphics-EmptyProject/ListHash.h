#pragma once
//#include"List.h"
#include<list>
#include"THashTable.h"

class TListHashTable:public THashTable
{
protected:
	std::list<TRecord> *pList;
	int TabSize;
	int CurrList;
	std::list<TRecord>::iterator CurrI;
public:
	TListHashTable(int Size = MaxSize);
	virtual ~TListHashTable();
	//
	virtual bool IsFull() const;
	//
	virtual bool FindRecord(TKey k);
	virtual int InsRecord(TKey k, TValue v);
	virtual int DelRecord(TKey k);

	virtual int Reset(void);
	virtual int IsTabEnd(void) const;
	virtual int GoNext(void);

	virtual TKey GetKey(void) const;
	virtual TValue GetVal(void) const;
};