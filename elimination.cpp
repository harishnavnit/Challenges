#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int m, n, values, count = 0;
	vector<int> initial;

	for (int i = 0; i < n; i++) {
		cin >> values;
		initial.push_back(values);
	}

	for (int i = 0; i < initial.size(); i++) {
		if (i % (m-1) == 0) {
			initial.erase(initial[i]);
		}
		count++;
		if (count == m) break;
	}

	for (int i = 0; i < initial.size(); i++) {
		cout << initial[i] << " " ;
	}

	return 0;
}