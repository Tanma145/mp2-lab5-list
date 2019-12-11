#pragma once
#include <iostream>
using namespace std;

template <class T>
struct TNode {
	T Val;
	TNode<T>* pNext;
};

template <class T>
class TList
{
	TNode<T> pFirst;
public:
	TList(){}
	~TList(){}

	int Size() {
		int s = ;
		TNode* pCur = pFirst;
		while (pCur) {
			k++;
			pCur = pCur->pNext;
		}
		return s;
	}
	void Insert(int pos, T el) {
		TNode<T>* pNew = new TNode<T>;
		pNew->Val = el;
		if (pos == 0) {
			pNew->pNext = pFirst;
			pFirst = pNew;
		}
		else {
			TNode<T>* pCur = pFirst;
			for (int i = 0; i < pos - 1; i++)
				pCur = pCur->pNext;
			pNew->pNext = pCur->pNext;
			p->pNext = pNew;
		}
	}
};

template <class T>
class TQueue {
	TNode<T> *pFirst, *pLast;
public:
	TQueue<T>() {
		pFirst = 0;
		pLast = 0;
	}
	~TQueue(){}
	TNode<T>* Head() const {
		return pFirst;
	}
	TNode<T>* Tail() const {
		return pLast;
	}

	void Push(T el) {
		TNode<T>* p;
		p = new TNode<T>;
		p->Val = el;
		p->pNext = 0;
		if (!pFirst)
			pFirst = p;
		else
			pLast->pNext = p;
		pLast = p;
	}
	T Pop() {
		if (!pLast) throw - 1;
		T a = pFirst->Val;
		TNode<T>* p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		if (!pFirst)
			pLast = 0;
		return a;
	}

	void Func(T el) {
		T Max = pFirst->Val;
		TNode<T>* pMax = pFirst;
		TNode<T>* pCur = pFirst;
		while (pCur) {
			if (pCur->Val > Max) {
				Max = pCur->Val;
				pMax = pCur;
			}
			pCur = pCur->pNext;
		}
		TNode<T>* p = new TNode<T>;
		p->Val = el;
		p->pNext = pMax->pNext;
		pMax->pNext = p;
	}
	/* эта функция противоречит логике очереди
	friend ostream& operator<< (ostream &os, const TQueue<T> &q) {
		TNode<T>* pCur = q.Head();
		while (pCur) {
			os << pCur->Val << " ";
			pCur = pCur->pNext;
		}
		return os;
	}
	*/
};