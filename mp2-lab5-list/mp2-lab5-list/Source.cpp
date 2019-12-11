#include "TList.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	TQueue<int> q;
	q.Push(4);
	q.Push(2);
	q.Push(9);
	q.Push(3);
	q.Push(5);
	cout << q << endl;
	q.Func(7);
	cout << q;
	_getch();
	return 0;
}