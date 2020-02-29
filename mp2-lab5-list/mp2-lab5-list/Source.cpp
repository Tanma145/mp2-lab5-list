#include "TList.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	TList<int> list;
	//list.InsFirst(10);
	//for (list.Reset(); !list.IsEnd(); list.GoNext()) {
	//	cout << list.GetCurr() << " ";
	//}
	cout << "uwu" << endl;
	int a;
	do{
		cin >> a;
		list.InsOrder(a);
		cout << list.GetLen() << ": ";
		for (list.Reset(); !list.IsEnd(); list.GoNext()) {
			cout << list.GetCurr() << " ";
		}
		cout << endl;
	} while (a != 0);
	cout << endl;

	/*
	list.DelFirst();
	cout << list.GetLen() << ": ";
	for (list.Reset(); !list.IsEnd(); list.GoNext())
		cout << list.GetCurr() << " ";
	cout << endl;
	*/

	list.DelList();
	cout << list.GetLen() << ": ";
	for (list.Reset(); !list.IsEnd(); list.GoNext())
		cout << list.GetCurr() << " ";
	cout << endl;
	
	_getch();
	return 0;
}