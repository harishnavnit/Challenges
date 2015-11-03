#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool> v;

void printResult();
bool populateVector(int );
void sieveOfEratosthenes(int );

int main(int argc, char *argv[])
{
  int bound;
  cout << "Upper bound = ";
  cin >> bound;
  sieveOfEratosthenes(bound);
  return 0;
}

void printResult()
{
  for (int i = 0; i < v.size(); i++) {
	if (v[i]) cout << i << ", ";
  }
  return;
}

/* An approximate method
 * Populates 5 times the bound indexes of the vector
 */
bool populateVector(int bound)
{
  fill(v.begin(), v.begin()+(bound*5), true);
}

void sieveOfEratosthenes(int bound)
{
  bool populateCompletionFlag = populateVector(bound);
  if (populateCompletionFlag)	cout << "Done";
  else cout << "Failed";
  if (bound > 2) {
	for (int i = 0; i < bound; i++) {
	  if (v[i]) {
		for (int j = 2; i*j < v.size(); j++) {
		  v[i*j] = false;
		}
	  }
	}
  } else {
	if (bound == 1) {
	  v[2] = true;
	  fill(v.begin() + 3, v.end(), false);
	} else if (bound == 2) {
	  v[2] = true;
	  v[3] = true;
	  fill(v.begin() + 4, v.end(), false);
	}
  }
  printResult();
}