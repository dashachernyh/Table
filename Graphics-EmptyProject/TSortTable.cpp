
#include"TSortTable.h"

void TSortTable::SortData(void)
{
	switch (SortMethod)
	{
	case SELECT_SORT:
			SelectSort(); break;
	case QUICK_SORT:
		QuickSort(); break;
	}
}

void TSortTable::SelectSort()
{
	int min = 0;
	for (int i = 0; i < DataCount; i++)
	{
		min = i;
		for (int j = i+1; j < DataCount; j++)
		{
			Efficiency++;
			if (MasRec[min] > MasRec[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			Efficiency++;
			TRecord tmp = MasRec[i];
			MasRec[i] = MasRec[min];
			MasRec[min] = tmp;
		}
		
	}
}

void TSortTable::QuickSort()
{
	QuickSorter(0, DataCount - 1);
}

void TSortTable::QuickSorter(int first, int last)
{
	TRecord elem = MasRec[(first + last) / 2];
	int i = first, j = last;
	while (i < j)
	{
		while (MasRec[i] < elem)
		{
			Efficiency++;
			i++;
		}
		while (MasRec[j] > elem)
		{
			Efficiency++;
			j--;
		}
		if (i <= j)
		{
			Efficiency++;
			TRecord tmp = MasRec[i];
			MasRec[i] = MasRec[j];
			MasRec[j] = tmp;
			i++;
			j--;
		}
		if (first < j)
		{
			QuickSorter(first, j);
		}
		if (i < last)
		{
			QuickSorter(i, last);
		}
	}
}

TSortTable::TSortTable(const TScanTable &tab)
{
	*this = tab;
}

TSortTable& TSortTable::operator =(const TScanTable &tab)
{
	if (MasRec != NULL)
	{
		delete[]MasRec;
		MasRec = NULL;
	}
	TabSize = tab.GetTabSize();
	DataCount = tab.GetDataCount();
	MasRec = new TRecord[TabSize];
	for (int i = 0; i < DataCount; i++)
	{
		MasRec[i] = tab.MasRec[i];
	}
	SortData();
	pCurr = 0;
	return *this;
}

bool TSortTable::FindRecord(TKey k)
{
	int i, i1 = 0, i2 = DataCount - 1;    //границы оюласти поиска
	while (i1<=i2)
	{
		Efficiency++;
		i = (i1 + i2) / 2;
			if (MasRec[i].Key == k)
			{
				i1 = i + 1;
				i2 = i;
				break;
			}
			if (MasRec[i].Key > k)  i2 = i - 1;
			else i1 = i + 1;
	}
	if((i2<0) || (MasRec[i2].Key<k)) i2++;
		pCurr=i2;
	if (i2 < DataCount && (MasRec[i].Key == k))
		{
			return true;
		}
	return false;
}

int TSortTable::InsRecord(TKey k, TValue v)
{
	if (IsFull())
	{
		return TadFull;
    }
	else
	{
		bool res = FindRecord(k);
		if (res == true)
		{
			return DuplRec;
		}
		else
		{
			for (int i = DataCount; i > pCurr; i--)
			{
				MasRec[i] = MasRec[i - 1];
				Efficiency++;
			}
			MasRec[pCurr] = TRecord(k, v);
			DataCount++;
			return TabOk;
		}
	}
}

int TSortTable::DelRecord(TKey k)
{
	if (IsEmpty())
	{
		return TabEmpty;
	}
	else
	{
		bool rez = FindRecord(k);
		if (rez == false)
		{
			return TabNoRec;
		}
		else
		{
			for (int i =pCurr; i < DataCount-2; i++)
			{
				MasRec[i] = MasRec[i + 1];
				Efficiency++;
			}
		//MasRec[DataCount]=NULL;	
			DataCount--;
			return TabOk;
		}
	}
}