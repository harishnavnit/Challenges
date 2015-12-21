/* Convert an infix expression to postfix notation */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

/* Represent the types of tokens */
vector<char> tokens;
vector<char> tokenizedString;

/* Function prototypes */
void populateTokenVector();
vector<char> tokenize(string );
string infixToPostfix(string );

int main(int argc, char *argv[])
{
    string infix;
    istream &in;
    cout << "\nEnter the infix expression : ";
    cin >> infix;

    cout << "\nPostfix notation for the expression = " << infixToPostfix(infix) << endl;

    return 0;
}

/* Populate the token vector with types of tokens */
void populateTokenVector()
{
    for (int i = 0; i < tokens.size(); i++) {
        tokens.push_back(';');
        tokens.push_back('+');
        tokens.push_back('-');
        tokens.push_back('*');
        tokens.push_back('/');
        tokens.push_back('=');
        tokens.push_back('(');
        tokens.push_back(')');
    }
}

/* Tokenize the input */
vector<char> tokenize(string exp)
{
    string val;
    for (int i = 0; i < exp.length(); i++) {
        // if the char of the string is one among the known tokens
        if (std::find(tokens.begin(), tokens.end(), exp[i]) != tokens.end()) {
            tokenizedString.push_back(exp[i]);
        } else {
            // the character could be a value
            if (exp[i] >= 48 && exp[i] <= 57)
        }
    }
}

/*
 * Method to convert Polish to Reverse Polish notation
 * i.e infix to postfix notation
 */
string infixToPostfix(string infix)
{
    string postfix;
    for (int i = 0; i < infix.length(); i++) {
        
    }
    return postfix;
}