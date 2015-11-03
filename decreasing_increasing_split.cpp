/* Write a program that checks if an input array can be split into two(one increasing and the other decreasing) */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

/* Function prototype */
bool can_be_split(int [], int);

/* Main method */
int main(int argc, char const* argv[])
{
    int arr[10],n;

    cout<<"\nEnter the size of the array : ";
    cin>>n;

    cout<<"\nEnter the array elements : ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    if(can_be_split(arr, n)) {
        cout<<"\nThe array can be split into two halves of increasing and decreasing sub-arrays\n";
    }
    else {
        cout<<"\nThis array can't be split into increasing and decreasing parts\n";
    }

    cout<<endl<<endl;

    return 0;
}

/* Function definition */
bool can_be_split(int a[10], int size) {
    int inc_flag = 0, dec_flag  = 0;

    for(int i =1; i<size; i++) {
        /* Check for the increasing flag */
        if(a[i] > a[i-1]) {
            continue;
        }
        else {
            inc_flag += 1;
        }

        /* Check for the decreasing flag */
        if(a[i] < a[i-1]) {
            continue;
        }
        else {
            dec_flag += 1;
        }
    }

    return (inc_flag + dec_flag  == 2);
}
