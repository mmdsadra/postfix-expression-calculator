#include <cmath>
#include "Header.h"
#include <string>
#include <iostream>

using namespace std;

int fact(int n) {
    if (n <= 0)
        return 1;
    return fact(n - 1) * n;
}

int prec(char c)
{
    if (c == '(')
        return 7;
    else if (c == 's' || c == 'c')
        return 6;
    else if (c == '!')
        return 5;
    else if (c == '^')
        return 4;
    else if (c == '~')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool precd(char c1, char c2) {
    int top = prec(c1);
    int inf = prec(c2);
    if ((top == 4 && inf == 4) || (top == 3 && inf == 3) || top == 7 || inf == 7)
        return false;
    else if (top >= inf)
        return true;
    else
        return false;
}

string infixToPostfix(string s)
{
    Stack<char> st;
    string result = "";
    char temp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'x' || (s[i] >= '0' && s[i] <= '9'))
            result += s[i];
        else {
            if (s[i] == ')') {
                while (!st.empty()) {
                    if (st.top() == '(') {
                        st.pop();
                        break;
                    }
                    else {
                        result += st.top();
                        st.pop();
                    }
                }
            }
            else {
                if (s[i] == 's') {
                    i += 2;
                    temp = 's';
                }
                else if (s[i] == 'c') {
                    i += 2;
                    temp = 'c';
                }
                else if (s[i] == '-' && (s[i - 1] == 'x' || isdigit(s[i - 1]) || s[i - 1] == ')'))
                    temp = '-';
                else if (s[i] != '-')
                    temp = s[i];
                else
                    temp = '~';
                while (!st.empty()) {
                    if (precd(st.top(), temp)) {
                        result += st.top();
                        st.pop();
                    }
                    else
                        break;
                }
                st.push(temp);
            }

        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    result += '\0';
    cout << result << endl;
    return result;
}

float calculatePostfix(string post_exp, double x1)
{
    Stack<double> stack;
    int i = 0;
    while (post_exp[i] != '\0') {
        if (post_exp[i] == 'x')
            stack.push(x1);
        else if (post_exp[i] >= '0' && post_exp[i] <= '9')
            stack.push(post_exp[i] - '0');
        else {
            double x, y;
            switch (post_exp[i])
            {
            case '!':
                x = stack.top();
                stack.pop();
                stack.push(fact(x));
                break;
            case 's':
                x = stack.top();
                stack.pop();
                stack.push(sin((int)x));
                break;
            case 'c':
                x = stack.top();
                stack.pop();
                stack.push(cos((int)x));
                break;
            case '^':
                x = stack.top();
                stack.pop();
                y = stack.top();
                stack.pop();
                stack.push(pow(y, x));
                break;
            case'*':
                x = stack.top();
                stack.pop();
                y = stack.top();
                stack.pop();
                stack.push(x * y);
                break;
            case'/':
                x = stack.top();
                stack.pop();
                y = stack.top();
                stack.pop();
                stack.push(y / x);
                break;
            case'+':
                x = stack.top();
                stack.pop();
                y = stack.top();
                stack.pop();
                stack.push(y + x);
                break;
            case'-':
                x = stack.top();
                stack.pop();
                y = stack.top();
                stack.pop();
                stack.push(y - x);
                break;
            case'~':
                x = stack.top();
                stack.pop();
                stack.push(-x);
                break;
            default:
                break;
            } 
        }
        i++;
    }
    return stack.top();
}



int main()
{
    string exp = "";

    getline(cin, exp);
    exp = infixToPostfix(exp);
    cout << "------------------" << endl;
    int x;
    for (int i = -10; i <= 10; i++)
    {
        cout << "x = " << i << " : " << calculatePostfix(exp, i) << endl;
    }
    cout << "------------------" << endl;
    cout << "Enter x:" << endl;
    cin >> x;
    cout << calculatePostfix(exp, x);
    return 0;
}