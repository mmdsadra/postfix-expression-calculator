#pragma once

#define MAX 1000

template<typename T>
class Stack {
private:
	int size = -1;
	T a[1000];
public:
	void pop() {
		size--;
	}
	void push(T x) {
		a[++size] = x;
	}
	bool empty() {
		return size == -1;
	}
	T top() {
		if(!empty())
			return a[size];
	}
	int Size() {
		return size + 1;
	}
};




//
//template<typename T>
//class Stack
//{
//    int topel;
//public:
//    T myStack[MAX]; //stack array
//
//    Stack() { topel = -1; }
//    bool push(T x);
//    T pop();
//    bool empty();
//    T top();
//    int Size();
//};
//
//template<typename T>
//T Stack<T>::top() {
//    return myStack[topel];
//}
//
////pushes element on to the stack
//template<typename T>
//bool Stack<T>::push(T item)
//{
//    if (topel >= (MAX - 1)) {
//        cout << "Stack Overflow!!!";
//        return false;
//    }
//    else {
//        myStack[++topel] = item;
//        cout << item << endl;
//        return true;
//    }
//}
//
////removes or pops elements out of the stack
//template<typename T>
//T Stack<T>::pop()
//{
//    if (topel < 0) {
//        cout << "Stack Underflow!!";
//        return 0;
//    }
//    else {
//        T item = myStack[topel--];
//        return item;
//    }
//}
//
////check if stack is empty
//template<typename T>
//bool Stack<T>::empty()
//{
//    return (topel < 0);
//}
//
//template<typename T>
//inline int Stack<T>::Size()
//{
//    return topel;
//}