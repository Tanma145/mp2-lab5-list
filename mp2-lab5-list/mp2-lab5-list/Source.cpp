#include "TPolynomial.h"
#include <iostream>
#include <conio.h>
#define size 50
using namespace std;

int main() {
	TPolynomial pol1, pol2;
	cout << "Enter first polynomial" << endl;
	cin >> pol1;
	cout << "Enter second polynomial" << endl;
	cin >> pol2;

	cout << pol1 << " + " << pol2 << " = " << pol1 + pol2;

	_getch();
	return 0;
}