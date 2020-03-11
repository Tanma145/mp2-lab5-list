#pragma once
#include "THeadList.h"
struct TMonomial {
	double coeff;
	int px, py, pz;
	bool operator== (TMonomial a) {
		return ((px == a.px) && (py == a.py) && (pz == a.pz));
	}
	bool operator> (TMonomial a) {
		return ((px > a.px) || (px <= a.px) && (py > a.py) || (px <= a.px) && (py <= a.py) && (pz > a.pz));
	}
	bool operator< (TMonomial a) {
		return ((px < a.px) || (px >= a.px) && (py < a.py) || (px >= a.px) && (py >= a.py) && (pz < a.pz));
	}
	bool operator>= (TMonomial a) {
		return ((px >= a.px) || (px < a.px) && (py >= a.py) || (px < a.px) && (py < a.py) && (pz >= a.pz));
	}
	bool operator<= (TMonomial a) {
		return ((px <= a.px) || (px > a.px) && (py <= a.py) || (px > a.px) && (py > a.py) && (pz <= a.pz));
	}
	void operator+= (TMonomial mon) {
		if (*this == mon) {
			coeff += mon.coeff;
		}
		else
			throw 0;
	}
	TMonomial operator+ (TMonomial mon) {
		TMonomial res = *this;
		res += mon;
		return res;
	}
	friend ostream& operator<< (ostream& os, const TMonomial& mon) {
		if (mon.coeff != 0) {
			if (mon.coeff < 0)
				os << "-";
			os << " " << abs(mon.coeff) << "x^" << mon.px << "y^" << mon.py << "z^" << mon.pz;
		}
		return os;
	}
};

class TPolynomial : public THeadList<TMonomial> {
public:
	TPolynomial():THeadList<TMonomial>() {
		pHead->Val.pz = -1;
	}
	TPolynomial(TPolynomial& p) : THeadList<TMonomial>() {
		pHead->Val.pz = -1;
		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			TMonomial mon = p.pCurr->Val;
			InsLast(mon);
		}
	}
	TPolynomial(int arr[][2], int size) :THeadList<TMonomial>() {
		pHead->Val.pz = -1;
		for (int i = 0; i < size; i++) {
			TMonomial mon;
			mon.coeff = arr[i][0];
			mon.px = arr[i][1] / 100;
			mon.py = arr[i][1] / 10 % 10;
			mon.pz = arr[i][1] % 10;
			InsLast(mon);
		}
	}
	void operator+= (TMonomial&);
	TPolynomial operator+ (TMonomial&);
	void operator*= (TMonomial&);
	TPolynomial operator* (TMonomial&);
	void operator+= (TPolynomial&);
	friend ostream& operator<< (ostream& os, TPolynomial& pol) {
		os << pol.pFirst->Val;
		for (pol.Reset(); !pol.IsEnd(); pol.GoNext()) {
			if (pol.pCurr == pol.pFirst) continue;
			if (pol.pCurr->Val.coeff >= 0) os << " +";
			os << pol.pCurr->Val;
		}
		return os;
	}
};

void TPolynomial::operator+=(TMonomial& mon) {
	for (Reset(); !IsEnd(); GoNext()) {
		if (pCurr->Val == mon) {
			pCurr->Val += mon;
			if (!pCurr->Val.coeff)
				DelCurr();
			return;
		}
		if (mon > pCurr->Val) {
			InsCurr(mon);
			return;
		}
		InsLast(mon);
	}
}

TPolynomial TPolynomial::operator+(TMonomial& mon) {
	TPolynomial res = *this;
	res += mon;
	return res;
}

void TPolynomial::operator*=(TMonomial& mon) {
	for (Reset(); !IsEnd(); GoNext()) {
		pCurr->Val.coeff *= mon.coeff;
		pCurr->Val.px += mon.px;
		pCurr->Val.py += mon.py;
		pCurr->Val.pz += mon.pz;
	}
}

TPolynomial TPolynomial::operator*(TMonomial& mon) {
	TPolynomial res = *this;
	res *= mon;
	return res;
}

void TPolynomial::operator+=(TPolynomial& q) {
	TMonomial pm, qm, rm;
	Reset();
	q.Reset();
	while (!q.IsEnd()) {
		pm = pCurr->Val;
		qm = q.pCurr->Val;
		if (pm > qm)
			GoNext();
		else
			if (pm < qm) {
				InsCurr(qm);
			}
			else {
				rm = pm;
				rm.coeff += qm.coeff;
				pCurr->Val = rm;
				if (rm.coeff == 0)
					DelCurr();
				GoNext();
				q.GoNext();
			}
	}
}

