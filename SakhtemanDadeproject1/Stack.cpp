//#include "C:\Users\Zeus\source\repos\SakhtemanDadeproject1\SakhtemanDadeproject1\Stack.h"
//
////template<class T>
////Stack<T>::Stack()
////{
////	MAX = 2;
////	a = new T[MAX];
////	size = -1;
////}
//
//template<class T>
//bool Stack<T>::empty()
//{
//	return size == -1;
//}
//
//template<class T>
//T Stack<T>::top()
//{
//	if (!empty())
//		return a[size];
//	
//}
//
////template<class T>
////T Stack<T>::pop()
////{
////	if (!empty())
////		return a[size--];
////	
////}
////
////template<class T>
////void Stack<T>::push(T x)
////{
////	if(size < MAX - 1)
////		a[++size] = x;
////	else {
////		T* tmp = new T[(MAX * 2)];
////		for (int i = 0; i < MAX; i++)
////		{
////			tmp[i] = a[i];
////		}
////		a = tmp;
////		MAX *= 2;
////		a[++size] = x;
////	}
////}
//
//template<class T>
//int Stack<T>::Size()
//{
//	return size + 1;
//}
//
//
//
