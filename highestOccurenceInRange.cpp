#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> digitCounter;

bool isPrime(int );
void initializeMapCounter();
void incrementDigitCount(string );
vector<int> tokenizeInteger(int );
int highestOccurringDigit(int, int );

int main(int argc, char *argv[])
{
  int l, r;
  cout << "Left bound : " << endl;
  cin >> l;
  cout << "Right bound : " << endl;
  cin >> r;
  cout << "Highest occurring digit in the range " << l << " - " << r << " is : " << highestOccurringDigit(l, r);
  return 0;
}

bool isPrime(int a)
{
  int count = 0;
  if (a == 2 || a == 3)						return true;
  else if ( (a != 2) && (a % 2 == 0) )		return false;
  else {
	for (int i = 1; i <= a; i++) {
	  if (a % i == 0)	++count;
	}
  }
  if (count == 2)	return true;
  else return false;
}

void initializeMapCounter()
{
  digitCounter["zero"] 	= 0;
  digitCounter["one"]	= 0;
  digitCounter["two"]	= 0;
  digitCounter["three"]	= 0;
  digitCounter["four"]	= 0;
  digitCounter["five"]	= 0;
  digitCounter["six"]	= 0;
  digitCounter["seven"]	= 0;
  digitCounter["eight"]	= 0;
  digitCounter["nine"]	= 0;
}

void incrementDigitCount(string )
{
  digitCounter[string] += 1;
}

vector<int> tokenizeInteger(int numeric)
{
  vector<int> v;
  while (numeric >= 10) {
	v.push_back(numeric%10);
	numeric /= 10;
  }
  v.push_back(numeric);
  return v;
}

int highestOccurringDigit(int left, int right)
{
  vector<int> nums, tokenizedContents;

  for (int i = left; i < right; i++) {
	if (isPrime(i))	nums.push_back(i);
  }

  for (int i = 0; i < nums.size(); i++) {
	tokenizedContents = tokenizeInteger(nums[i]);
	for (int j = 0; j < tokenizedContents.size(); j++) {
	  switch(tokenizedContents[j]) {
		case 0 : {
		  incrementDigitCount("zero");
		  break;
		}
		case 1 : {
		  incrementDigitCount("one");
		  break;
		}
		case 2 : {
		  incrementDigitCount("two");
		  break;
		}
		case 3 : {
		  incrementDigitCount("three");
		  break;
		}
		case 4 : {
		  incrementDigitCount("four");
		  break;
		}
		case 5 : {
		  incrementDigitCount("five");
		  break;
		}
		case 6 : {
		  incrementDigitCount("six");
		  break;
		}
		case 7 : {
		  incrementDigitCount("seven");
		  break;
		}
		case 8 : {
		  incrementDigitCount("eight");
		  break;
		}
		case 9 : {
		  incrementDigitCount("nine");
		  break;
		}
		default : {
		  cerr << "Unknown digit format" << endl;
		}
	  }
	}
  }
  return max_element(digitCounter.begin(), digitCounter.end());
}