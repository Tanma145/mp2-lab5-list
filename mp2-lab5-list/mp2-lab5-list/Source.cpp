#include "TPolynomial.h"
#include <iostream>
#include <conio.h>
#define size 1
using namespace std;

int main() {
	int arr[size][2];
	for (int i = 0; i < size; i++) {
		cout << "Enter coeff";
		cin >> arr[i][0];
		cout << "Enter powers";
		cin >> arr[i][1];
	}
	TPolynomial pol(arr, size);
	cout << pol;

	/*
	list.DelFirst();
	cout << list.GetLen() << ": ";
	for (list.Reset(); !list.IsEnd(); list.GoNext())
		cout << list.GetCurr() << " ";
	cout << endl;
	*/
	
	_getch();
	return 0;
}