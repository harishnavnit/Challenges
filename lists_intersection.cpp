/* Program to find the intersection of two lists */

#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void print_intersection(list<int>, list<int>);

/* Begining of Main method */
int main(int argc, char const *argv[])
{
	list<int> l1, l2;
	int input;
	char ans;

	cout<<"\nEnter elements in list ?(Y/N) : ";
	cin>>ans;
	if(ans == 'Y' || ans == 'y')
		cout<<"\nEnter the elements of the first list"<<endl;
	while(ans == 'Y' || ans == 'y') {
		cin>>input;
		l1.push_back(input);
	}

	cout<<"\nEnter elements in the second list ? (Y/N) : ";
	cin>> ans;
	if(ans == 'Y' || ans == 'y')
		cout<<"\nEnter elements of the second list"<<endl;
	while(ans == 'Y' or ans == 'y') {
		cin>>input;
		l2.push_back(input);
        cout << "Pushed " << input << "to the list"<<endl;
        cout << "Enter more ? (Y/N) : ";
        cin >> ans;
	}

	print_intersection(l1, l2);

	return 0;
}

/* Defining the method to find the intersection of the two lists */
void print_intersection(list<int> l1, list<int> l2) {

	list<int> :: iterator i, j;
	bool consists_flag = false;

	cout<<endl;

	for(i = l1.begin(); i != l1.end(); i++) {
		for(j = l2.begin(); j != l2.end(); j++) {

			if(*i == *j) {
				consists_flag = true;
			}
		}

		if(consists_flag) {
			cout<<" "<<*i<<" ";
		}
	}

	cout<<endl<<endl;
}
