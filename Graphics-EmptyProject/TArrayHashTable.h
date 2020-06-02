#pragma once
#include"THashTable.h"

#define TabHashStep 7

class TArrayHashTable : public THashTable
{
protected:
	TRecord *MasRec;
	int TabSize;
	int HashStep;
	int FreePos;
	int CurrPos;
	TRecord Mark;  //маркер удаленных сзаписей
	TRecord Empty;  //маркер свободных строк

	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }   //функция открытого перемештвания

public:
	TArrayHashTable(int size = MaxSize, int step = TabHashStep);
	virtual ~TArrayHashTable();

	virtual bool IsFull() const { return DataCount >= TabSize; }

	virtual bool FindRecord(TKey k);
	virtual int InsRecord(TKey k, TValue v);
	virtual int DelRecord(TKey k);

	virtual int Reset(void);
	virtual int IsTabEnd(void) const;
	virtual int GoNext(void);

	virtual TKey GetKey(void) const;
	virtual TValue GetVal(void) const;

	friend istream& operator >>(istream& is, TArrayHashTable &tab)
	{
		TKey k;
		TValue v;
		int data_count;
		tab.CurrPos = 0;
		cout << "enter DataCount" << endl;
		is >> data_count;
		for (int i=0;i<data_count;i++)
		{
			tab.CurrPos = i;
			is >> k;
			is >> v;
			tab.InsRecord(k,v);
		}
		return is;
	}

};