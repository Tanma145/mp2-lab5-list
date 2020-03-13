#include "TPolynomial.h"
#include <iostream>
#include <conio.h>
#define size 2
using namespace std;

int main() {/*
	int arr[size][2];
	for (int i = 0; i < size; i++) {
		cout << "Enter coeff";
		cin >> arr[i][0];
		cout << "Enter powers";
		cin >> arr[i][1];
	}
	TPolynomial pol1(arr, size);
	for (int i = 0; i < size; i++) {
		cout << "Enter coeff";
		cin >> arr[i][0];
		cout << "Enter powers";
		cin >> arr[i][1];
	}
	TPolynomial pol2(arr, size);
	cout << pol1 << endl;
	cout << pol2 << endl;
	cout << (pol1 == pol2) << endl;*/

    TMonomial mon1, mon2, mon3, mon4, mon5;
    TPolynomial pol1, pol2;

    mon1.coeff = 1;
    mon1.px = 1;
    mon1.py = 2;
    mon1.pz = 3;
    mon2.coeff = 3;
    mon2.px = 4;
    mon2.py = 5;
    mon2.pz = 6;

    pol1 += mon1;
    pol1 += mon2;

    mon3.coeff = 4;
    mon3.px = 7;
    mon3.py = 8;
    mon3.pz = 9;

    pol1 *= mon3;

    mon4.coeff = 12;
    mon4.px = 11;
    mon4.py = 13;
    mon4.pz = 15;
    mon5.coeff = 4;
    mon5.px = 8;
    mon5.py = 10;
    mon5.pz = 12;
    pol2 += mon4;
    pol2 += mon5;

    cout << pol1 << endl;
    cout << pol2 << endl;
    cout << (pol1 == pol2) << endl;

	
	_getch();
	return 0;
}