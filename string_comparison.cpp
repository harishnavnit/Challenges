#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool duplicates_exist(vector<string>);

int main(int argc, char *argv[])
{
	int string_count;
	string current;
	vector<string> destination;

	cout << "\nEnter the number of strings : ";
	cin >> string_count;

	for (int i = 0; i < string_count; i++) {
		cout << "\nEnter string " << i+1 << " : ";
		cin >> current;
		destination.push_back(current);
	}

	cout << ( duplicates_exist(destination) ? "\nInternal matches found" : "\nNo matches found" ) << endl;

	return 0;
}

bool duplicates_exist(vector<string> array)
{
	sort(array.begin(), array.end());

	for (int i = 0; i < array.size(); i++) {
		for (int j = i+1; j < array.size(); j++) {
			if (array[i] == array[j]) {
				return true;
				break;
			}
		}
	}
	return false;
}