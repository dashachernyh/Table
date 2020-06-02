#include<iostream>
using namespace std;
#include "TScanTable.h"
#include"TSortTable.h"
#include"TArrayHashTable.h"
#include "TTreeTable.h"
#include "conio.h"
int main()
{
	int pos, size;
	/*cout << "write size of table" << endl;
	cin >> size;
	TScanTable t(size);
	cout << "enter of table " << endl;
	cin >> t;
	cout << t << endl;
	t.InsRecord(123, "24");
	t.InsRecord(231, "567");
	cout << t;
	t.DelRecord(123);
	cout << t;
	TSortTable t2(size);
	cin>> t2;
	cout << t2;
	bool p=t2.FindRecord(123);
	cout << p << endl;
	cout << t2.GetKey() << " " << t2.GetVal() << endl;
	t2.DelRecord(123);
	cout << t2;
	TArrayHashTable t3(size);
	cin >> t3;
	cout << t3;
	bool res = t3.FindRecord(12);
	cout << res << endl;
	cout << t3.GetKey() << " " << t3.GetVal() << endl;
	t3.InsRecord(15, "345");
	cout << t3;
	t3.DelRecord(12);
	cout << t3;*/
	TTreeTable tree;
	cin >> tree;
	cout << tree;
	cout << tree.FindRecord(4);
	cout << tree.GetKey() << " " << tree.GetVal()<<std::endl;
	tree.InsRecord(8, "147");
	cout << tree;
	tree.DelRecord(7);
	cout << tree;
	_getch();
}