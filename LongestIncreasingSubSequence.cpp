#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const* argv[])
{
    int arr[10], size, count = 0;
    int start_index;
    map<int, int> ref;
    vector<int> lis;

    cout << "Size : ";              cin >> size;
    for (int i = 0; i < size; i++)  cin >> arr[i];

    for (int i = 0; i < size-1; i++) {
        start_index = i;
        count = 0;
        for (int j = 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                count++;
            }
            ref[count] = start_index;
        }
    }

    map<int, int> :: iterator itr;
    for (itr = ref.begin(); itr != ref.end(); ++itr)
        start_index = itr->second;

    cout << "\nThe longest increasing subsequence is " << endl;
    for (int i = start_index; i < size; i ++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    return 0;
}
