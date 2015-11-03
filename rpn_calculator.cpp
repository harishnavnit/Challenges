#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string input;
	cin >> input;

	stack<char> operations;

	for (int i = 0; i < input.size(); i++) {
		switch(input[i])
		{
			case '/': {
				if (!operations.empty()) {
					char A = operations.top();
					operations.pop();
					char B = operations.top();
					operations.pop();
					int a = (int)A;
					int b = (int)B;
					
					operations.push(a/b);
				} else cerr << "Empty stack" << endl;
			}
			case '+': {
				if (!operations.empty()) {
					char A = operations.top();
					operations.pop();
					char B = operations.top();
					operations.pop();
					int a = (int)A;
					int b = (int)B;
					
					operations.push(a+b);
				} else cerr << "Empty stack" << endl;
			}
			case '-': {
				if (!operations.empty()) {
					char A = operations.top();
					operations.pop();
					char B = operations.top();
					operations.pop();
					
					int a = (int)A;
					int b = (int)B;
					
					operations.push(a-b);
				} else cerr << "Empty stack" << endl;
			}
			case '*': {
				if (!operations.empty()) {
					char A = operations.top();
					operations.pop();
					char B = operations.top();
					operations.pop();
					int a = (int)A;
					int b = (int)B;
					
					operations.push(a*b);
				} else cerr << "Empty stack" << endl;
			}
			default : {
				operations.push(input[i]);
			}
		}
	}

	cout << "\nResult : " << operations.top();

	return 0;
}