#include "TPolynomial.h"
#include <iostream>
#include <conio.h>
#define size 2
using namespace std;

int main() {
    TMonomial mon1, mon2, mon3, mon4, mon5, mon6, mon7;
    TPolynomial pol1, pol2, pol3;

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
    cout << pol1 << endl;

    mon3.coeff = 4;
    mon3.px = 7;
    mon3.py = 8;
    mon3.pz = 9;
    mon4.coeff = -5;
    mon4.px = 10;
    mon4.py = 11;
    mon4.pz = 12;
    pol2 += mon3;
    pol2 += mon4;
    cout << pol2 << endl;

    mon5.coeff = 4;
    mon5.px = 8;
    mon5.py = 10;
    mon5.pz = 12;
    mon6.coeff = 7;
    mon6.px = 11;
    mon6.py = 13;
    mon6.pz = 15;
    mon7.coeff = -15;
    mon7.px = 14;
    mon7.py = 16;
    mon7.pz = 18;
    pol3 += mon5;
    pol3 += mon6;
    pol3 += mon7;
    cout << "pol3 =" << pol3 << endl;
    cout << "(pol1 * pol2) =" <<(pol1 * pol2) << endl;

    cout << ((pol1 * pol2) == pol3) << endl;
    
    
	
	_getch();
	return 0;
}