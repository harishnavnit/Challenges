/* Program to check if an expression has equal number of paranthesis */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool balancedExpression(string );

int main(int argc, char *argv[])
{
    string exp;
    cout << "Enter the expression : ";
    cin >> exp;

    if (balancedExpression(exp)) {
        cout << "\nWell formed expression with equal number of LPAREN and RPAREN" << endl;
    } else {
        cout << "\nIncorrect expression" << endl;
    }

    return 0;
}

bool balancedExpression(string exp)
{
    stack<char> s;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(')      s.push('(');
        if (exp[i] == ')') {
            if (s.empty()) {
                return false;
            } else {
                s.pop();
            }
        }
    }
    return s.empty();
}