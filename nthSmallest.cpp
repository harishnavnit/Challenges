/* Find the n-th smallest number in an array */

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/* Function prototype */
int find_n_thSmallest(int, int, int []);

/* Main method */
int main(int argc, char const* argv[])
{
    int arr[10], size, n;

    cout<<"\nEnter the size of the array : ";
    cin>>size;

    cout<<"\nEnter the value of n : ";
    cin>>n;

    cout<<"\nEnter the elements of the array : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    // Function call
    cout<<"\nThe "<<n<<"th smallest element in the array is "<<find_n_thSmallest(n, size, arr)<<endl;

    return 0;
}

int find_n_thSmallest(int n, int size, int arr[10]) {

    vector<int> v;

    for(int i=0; i<size; i++) {
        v.push_back(arr[i]);
    }

    sort(v.begin(), v.end());

    return v[n-1];
}
