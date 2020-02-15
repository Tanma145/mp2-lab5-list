#include "TList.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	THeadList<int> list;
	//list.InsFirst(10);
	//for (list.Reset(); !list.IsEnd(); list.GoNext()) {
	//	cout << list.GetCurr() << " ";
	//}
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
	
	_getch();
	return 0;
}