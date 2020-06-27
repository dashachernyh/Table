#pragma once
#include<iostream>
#include<string>
using namespace std;
typedef int TKey;
typedef string TValue;

class TRecord
{
protected:
	TKey Key;
	TValue Val;
public:
	TRecord(TKey k = 0, TValue v = "") { Key = k; Val = v; }
	void SetKey(TKey k) { Key = k; }
	TKey GetKey(void) { return Key; }
	void SetVal(TValue v) { Val = v; }
	TValue GetVal() { return Val; }
	virtual void operator =(TRecord tr)
	{ 
		Key = tr.Key;
	    Val = tr.Val;
	}
	virtual int operator == (const TRecord & tr) { return (Key == tr.Key); }
	virtual int operator != (const TRecord & tr) { return (Key != tr.Key); }
	virtual int operator > (const TRecord & tr) { return (Key > tr.Key); }
	virtual int operator < (const TRecord & tr) { return (Key < tr.Key); }
	friend ostream& operator <<(ostream & os, const TRecord& tr)
	{
		return os << tr.Key << " " << tr.Val;
	}
	
	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
	friend class THashTable;
	friend class TArrayHashTable;
	friend class TTreeNode;
	friend class TTreeTable;
	friend class TListHashTable;
};