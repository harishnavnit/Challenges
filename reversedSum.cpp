/* Program to print the reversed sum of a two numbers */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int reverseNum(int );

int main()
{
    int a,b,sum;

    cout << "\nEnter two numbers : ";
    cin >> a >> b;

    int rev_num1 = reverseNum(a);
    int rev_num2 = reverseNum(b);
    cout << "rev_num1 = " << rev_num1 << endl;
    cout << "rev_num2 = " << rev_num2 << endl;
    sum = rev_num1 + rev_num2;

    cout << "\nReversed sum = " << reverseNum(sum)<< endl;

    return 0;
}

int reverseNum(int num)
{
    int rem, rev = 0;
    cout << "In reverseNum() ... " << endl;
    cout << "About to enter while loop : \n num = " << num << endl;
    while (num > 0) {
        rem = num % 10;
            cout << "rem = " << num < " % 10" << endl;
        num = num/10;
            cout << "num "
        rev = rev * 10 + rem;
    }
    return num;
}
