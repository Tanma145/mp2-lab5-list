#pragma once
#include <iostream>
using namespace std;

template <class T>
struct TNode {
	T Val;
	TNode<T>* pNext;
};

//СПИСОК
template <class T>
class TList{
protected:
	int pos, len;
	TNode<T> *pFirst, *pLast, *pCurr, *pPrev, *pStop;
public:
	TList(){
		pFirst = 0;
		pLast = 0;
		pCurr = 0;
		pPrev = 0;
		pStop = 0;
		len = 0;
		pos = -1;
	}
	~TList(){
	}

	int Size() {
		int s = 0;
		pCurr = pFirst;
		while (pCurr != pStop) {
			s++;
			pCurr = pCurr->pNext;
		}
		return s;
	}
	void InsFirst(T el) {
		TNode<T>* p = new TNode<T>;
		p->pNext = pFirst;
		p->Val = el;
		pFirst = p;
		if (!pLast) pLast = p;
		len++;
		pos++;
	}
	void InsLast(T el) {
		TNode<T>* p = new TNode<T>;
		pLast->pNext = p;
		p->pNext = pStop;
		p->Val = el;
		pLast = p;
		len++;
	}
	void InsCurr(T el) {
		TNode<T>* p = new TNode<T>;
		p->Val = el;
		if (pCurr == pFirst) InsFirst(el);
		else {
			pPrev->pNext = p;
			p->pNext = pCurr;
			len++;
			pos++;
			pCurr = p;
		}
	}
	void DelFirst() {
		TNode<T>* tmp = new TNode<T>;
		tmp = pFirst;
		delete pFirst;
		pFirst = tmp->pNext;
	}
	/*
	void Ins(int pos, T el) {
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
	}*/
	T GetCurr() {
		return pCurr->Val;
	}
	int GetLen() {
		return len;
	}
	void Reset() {
		pCurr = pFirst;
		pPrev = NULL;
		pos = 0;
	}
	void GoNext() {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	bool IsEnd() {
		return pCurr == pStop;
	}/*
	bool IsEmpty() {
		return pFirst == p
	}*/
	void InsOrder(T el) {
		if (pFirst == 0 || pFirst->Val < el)
			InsFirst(el);
		else
			if (el <= pLast->Val)
				InsLast(el);
			else
				for (Reset(); !IsEnd(); GoNext())
					if (pCurr->Val < el) {
						InsCurr(el);
						break;
					}
	}
};
//СПИСОК С ГОЛОВОЙ
template <class T>
class THeadList :public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList() : TList<T>() {
		pHead = new TNode<T>;
		pStop = pStop = pHead;
		pHead->pNext = pHead;
		pFirst = pHead;
	}
	void InsFirst(T el) {
		TList<T>::InsFirst(el);
		pHead->pNext = pFirst;
	}
	void DelFirst(T el) {
		TList<T>::DelFirst(el);
		pHead->pNext = pFirst;
	}
	~THeadList() {

	}
};
//ОЧЕРЕДЬ
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