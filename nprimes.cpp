#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/* Function prototypes */
bool isPrime(int );
int populatePrimes(int );
int printSumOfPrimes(vector<int> );

/* Main method */
int main(int argc, char *argv[])
{
  int range;
  cout << "Range = ";
  cin >> range;
  cout << "Sum = " << populatePrimes(range) << endl;
  return 0;
}

// Returns if a number is prime or not
bool isPrime(int n)
{
  int factorCount = 0;

  if (n == 2)							return true;
  else if ((n != 2) and (n%2 == 0))		return false;
  else {
	for (int i = 1; i <= n; i++) {
	  if (n % i == 0) ++factorCount;
	}
	if (factorCount == 2) return true;
	else return false;
  }
}

// Lists each prime number within range
int populatePrimes(int range)
{
  int itr = 2, pushed_back = 0;;
  vector<int> v;
  while (1) {
	if (isPrime(itr)) {
	  v.push_back(itr);
	  ++pushed_back;
	}
	if (! (pushed_back < range) ) break;
	++itr;
  }
  int sum = printSumOfPrimes(v);
  return sum;
}

// Prints the sum of prime numbers within range
int printSumOfPrimes(vector<int> v)
{
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
	sum += v[i];
  }
  return sum;
}