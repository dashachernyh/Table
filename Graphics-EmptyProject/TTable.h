#pragma once
#include "Record.h"
#include<fstream>

#define DuplRec -101   //дублированная запись
#define TebNoMem -102
#define TabOk 0        //ошибок нет
#define TabEmpty -103
#define TadFull -104
#define TabNoRec -105
#define WrongNum -106
#define MaxSize 20

class TTable
{
protected:
	int DataCount;   //кол-во записей в таблице
	int Efficiency;  //эффективность
public:
	TTable() { DataCount = 0; Efficiency = 0; }
	virtual ~TTable() {}

	
	int GetDataCount() const { return DataCount; }
	int GetEfficiency() const { return Efficiency; }
	void ClearEfficiency() { Efficiency = 0; }  //обнулили эффективность
	bool IsEmpty() const { return DataCount == 0; }
	virtual bool IsFull() const = 0;

	virtual bool FindRecord(TKey k) = 0;
	virtual int InsRecord(TKey k, TValue v) = 0;
	virtual int DelRecord(TKey k) = 0;

	virtual int Reset(void) = 0;
	virtual int IsTabEnd(void) const = 0;
	virtual int GoNext(void) = 0;

	virtual TKey GetKey(void) const = 0;
	virtual TValue GetVal(void) const = 0;

	friend ostream& operator<<(ostream &os, TTable &tab)
	{
		os << "Printing of table:" << endl;
		for (tab.Reset(); !tab.IsTabEnd(); tab.GoNext())
		{
			os << "Key: " << tab.GetKey() << " Val: " << tab.GetVal()<<endl;
		}
		return os;
	}

	void Print(System::Windows::Forms::DataGridView^ grid)
	{
		grid->ColumnCount = 2;
		grid->RowCount = DataCount;
		int i = 0;
		for (Reset(); !IsTabEnd(); GoNext())
		{
			grid[0, i]->Value = GetKey();
			grid[1, i]->Value = gcnew System::String(GetVal().c_str());
			i++;
		}
	}

	void Fprint (ofstream &of)
	{
		of << "Printing of table:" << endl;
		for (Reset(); !IsTabEnd();GoNext())
		{
			of << "Key: " <<GetKey()<<"   "<< " Val: " << GetVal() << endl;
		}

	}

	
};