//#pragma once
//
//template<class T>
//class Stack {
//private:
//	int size;
//	T* a;
//	int MAX;
//
//public:
//	Stack() {
//		MAX = 5;
//		a = new T[MAX]
//		size = -1;
//	}
//	bool empty();
//	T top();
//	T pop() {
//		if (!empty())
//			return a[size--];
//	}
//	void push(T x) {
//		if (size < MAX - 1)
//			a[++size] = x;
//		else {
//			T* tmp = new T[(MAX * 2)];
//			for (int i = 0; i < MAX; i++)
//			{
//				tmp[i] = a[i];
//			}
//			a = tmp;
//			MAX *= 2;
//			a[++size] = x;
//		}
//	}
//	int Size();
//
//};
//
