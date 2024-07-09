//#include <math.h>
//#include <stack>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//int fact(int n) {
//	if (n == 0)
//		return 1;
//	else
//		return fact(n - 1) * n;
//}
//
//bool isoperator(char ch) {
//	if (ch == '*' || ch == '-' || ch == '+' || ch == '/' || ch == '^')
//		return true;
//	
//	return false;
//}
//
//int prec(char c)
//{
//	if (c == '^')
//		return 3;
//	else if (c == '/' || c == '*')
//		return 2;
//	else if (c == '+' || c == '-')
//		return 1;
//	else
//		return -1;
//}
//
//
//void infixtopostfix(string& in, string& post) {
//	
//	stack<char> s;
//
//	for (int i = 0; i < in.length(); i++) 
//	{
//		if (isoperator(in[i])) {
//			if (in[i] == '-' && (i == 0 || isoperator(in[i - 1]) )) {
//				post += '-' + in[i + 1];
//				i++;
//				continue;
//			}
//
//			while (!s.empty() && prec(in[i]) <= prec(s.top())) {
//				post += " " + s.top();
//				s.pop();
//			}
//			s.push(in[i]);
//
//		}
//		else if (in[i] == 'x') {
//			post += 'x';
//		}
//		else if (in[i] == '(' || in[i] == ')') {
//			if (in[i] == '(')
//				s.push('(');
//			else {
//				while (s.top() != '(') {
//					post += ' ';
//					post += s.top();
//					s.pop();
//				}
//				s.pop();
//			}
//
//		}
//		else if (in[i] == '!') {
//			post += char(fact((int)(in[i - 1] - '0'))) + '0';
//		}
//		else if (in[i] == 's' || in[i] == 'c') {
//			if (in[i] == 's') {
//				i += 2;
//				post += sin(in[i + 1]);
//			}
//			else {
//				i += 2;
//				post += cos(in[i + 1]);
//			}
//		}
//		else {
//			post += in[i];
//		}
//		
//	}
//
//	while (!s.empty()) {
//		post += ' ';
//		post += s.top();
//		s.pop();
//	}
//}
//
//
//int main() {
//	std::string str, prestr;
//	int x;
//	getline(cin, str);
//	//getchar();
//	cin >> x;
//	string out = "";
//	infixtopostfix(str, out);
//	cout << out << endl;
//}
