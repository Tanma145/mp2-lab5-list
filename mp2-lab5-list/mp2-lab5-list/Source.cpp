#include "TList.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	TList<int> list;
	list.InsFirst(10);
	for (list.Reset(); !list.IsEnd(); list.GoNext()) {
		cout << list.GetCurr();
	}
	_getch();
	return 0;
}