#include <iostream>
#include <algorithm>

using namespace std;

/** FIXME : Improper Pattern printed */

/* Function prototypes */
void print_pattern(int, int);
void print_base_bottom(int, int);
void print_base_top(int, int);

/* Begining of the main method */
int main(int argc, char const* argv[])
{
    int height, base, choice;

    cout<<"\nEnter height and base of the triangle : ";
    cin>> height >> base;
    cout<<"\nSelect Pattern \n1. Base Top\n2. Base Bottom\n3. Triangular Pattern"<<endl;
    cout<<"\nEnter choice(1-3) : ";
    cin>>choice;

    switch(choice) {
        case 1 : {
                    print_base_top(height, base);
                    break;
                 }
        case 2 : {
                    print_base_bottom(height, base);
                    break;
                 }
        case 3 : {
                    print_pattern(height, base);
                    break;
                 }
        default : cerr<<"\nInvalid Choice ! "<<endl;
    }

    cout<<endl<<endl;
    return EXIT_SUCCESS;
}

/** Function definitions */
/* Prints a Right angled triangle,
 * descending downwards from it's base
 */
void print_base_top(int h, int b) {
    for(int i = 0; i < h; i++) {
        cout<<endl;
        for(int j = b-i; j > 0; j--) {
            cout<<" * ";
        }
    }
}

/* Prints a Right angled triangle,
 * ascending upwards from it's base
 */
void print_base_bottom(int h, int b) {
    for(int i = 0; i < h; i++) {
        cout<<endl;

        for(int j = 0; j <= i; j++) {
            cout<<" "<<"*";
        }
    }
}

/* Given equal dimensions, prints a
 * scalene triangle with the base at
 * the bottom
 */
void print_pattern(int h, int b) {
    for(int i = 1; i <= h; i++) {
        cout<<endl;
            for(int j = 0; j <= (b-i); j++)
                cout<<" ";

        if(i == 1)
            cout<<" *";
        else {
            for(int k = 1; k <= i; k++)
                cout<<"*"<<" ";
            cout<<"*";
        }
    }
}
