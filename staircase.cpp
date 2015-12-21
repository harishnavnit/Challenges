#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int stair_case_size;
	cin >> stair_case_size;

	for (int i = 1; i < stair_case_size; i++) {
		for (int j = 0; j < stair_case_size - i; j++) {
			cout << " ";
		}
		for (int k = 0; k < i; k++) {
			cout << "#";
		}
		cout << endl;
	}

	return 0;
}
