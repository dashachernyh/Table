#include "TArrayTable.h"
#include"TScanTable.h"

enum TSortMethod {SELECT_SORT, QUICK_SORT};
class TSortTable :public TArrayTable
{
private:
	TSortMethod SortMethod;
	void SortData(void);
	void SelectSort();
	void QuickSort();
	void QuickSorter(int first, int last);
public:
	TSortTable(int size = MaxSize) :TArrayTable(size) {}
	//~TSortTable() {}
	TSortTable(const TScanTable &tab);
	TSortTable& operator =(const TScanTable &tab);
	TSortMethod GetSortMethod(void) { return SortMethod; }

	virtual bool FindRecord(TKey k);
	virtual int InsRecord(TKey k, TValue v);
	virtual int DelRecord(TKey k);

	friend ostream& operator<<(ostream &os, TSortTable &tab)
	{
		tab.QuickSort();
		os << "Printing of table:" << endl;
		for (tab.Reset(); !tab.IsTabEnd(); tab.GoNext())
		{
			os << "Key: " << tab.GetKey() << " Val: " << tab.GetVal() << endl;
		}
		return os;
	}
};