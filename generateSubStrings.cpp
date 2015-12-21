/* Generate all substrings of an array/vector
 * HINT : use the begin(){+-}iter and/or end(){+-}iter
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateSubStrings(vector<int> );
vector<int> formSubString(int , int , vector<int> );

int main(int argc, char *argv[])
{
    int el;
    vector<int> v;
    while (cin >> el) {
        if (el == 99)   break;
        v.push_back(el);
    }

    generateSubStrings(v);
    return 0;
}

void generateSubStrings(vector<int> v)
{
    vector<int> temp;
    vector< vector<int> > substrings, iter;

    for (int i = 0; i < v.size(); i++) {
        temp = formSubString(v.begin(), v.begin() + i, v);
        substrings.push_back(temp);
        temp.clear();
    }

    cout << "Substrings are : ";
    for (int i = 0; i < substrings.size(); i++) {
        iter = substrings[i];
        for (int j = 0; j < iter.size(); j++) {
            cout << "{ " << iter[i][j] << ", ";
        }
        cout << " }, ";
    }
    cout << endl;
}

vector<int> formSubString(int from, int to, vector<int> v)
{
    vector<int> t;
    t.clear();
    for (int i = from; i <= to; i++) {
        t.push_back(v[i]);
    }
    return t;
}