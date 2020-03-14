#pragma once
#include "THeadList.h"
struct TMonomial {
	double coeff;
	int px, py, pz;
	bool operator== (TMonomial a) {
		return ((px == a.px) && (py == a.py) && (pz == a.pz));
	}
	bool operator> (TMonomial a) {
		return ((px > a.px) || (px == a.px) && (py > a.py) || (px == a.px) && (py == a.py) && (pz > a.pz));
	}
	bool operator< (TMonomial a) {
		return ((px < a.px) || (px == a.px) && (py < a.py) || (px == a.px) && (py == a.py) && (pz < a.pz));
	}
	bool operator>= (TMonomial a) {
		return *this > a || *this == a;
	}
	bool operator<= (TMonomial a) {
		return *this < a || *this == a;
	}
	TMonomial operator- () {
		coeff = -coeff;
		return *this;
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
	bool operator== (const TPolynomial&) const;
	TPolynomial& operator= (TPolynomial&);
	void operator+= (TMonomial&);
	void operator-= (TMonomial&);
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

inline bool TPolynomial::operator==(const TPolynomial &pol) const{
	TNode<TMonomial> *i1, *i2;
	i1 = pFirst;
	i2 = pol.pFirst;
	while (i1->Val == i2->Val && i1->Val.coeff == i2->Val.coeff && i1 != pStop && i2 != pStop) {
		i1 = i1->pNext;
		i2 = i2->pNext;
	}
	return (i1 == pStop) && (i2 == pol.pStop);
}

inline TPolynomial& TPolynomial::operator=(TPolynomial &pol){
	DelList();
	for (pol.Reset(); pol.IsEnd(); pol.GoNext()) {
		*this += pol.pCurr->Val;
	}
	return *this;
}

void TPolynomial::operator+=(TMonomial& mon) {
	for (Reset(); !IsEnd(); GoNext()) {
		if (mon == pCurr->Val) {
			pCurr->Val += mon;
			if (!pCurr->Val.coeff)
				DelCurr();
			return;
		}
		if (mon > pCurr->Val) {
			InsCurr(mon);
			return;
		}
	}
	InsLast(mon);
}

inline void TPolynomial::operator-=(TMonomial& mon){
	*this += -mon;
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
				q.GoNext();
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

