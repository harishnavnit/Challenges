#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tokenize(int );
void permute(vector<int> );

int main(int argc, char *argv[])
{
  int input;
  cout << "\nEnter input : ";
  cin >> input;
  tokenize(input);

  return 0;
}

void tokenize(int a)
{
  int p = a;
  vector<int> nums;

  while (p/10 > 0) {
	nums.push_back(p%10);
	p /= 10;
  }
  nums.push_back(p);
  permute(nums);
}

void permute(vector<int> v)
{
  int size = v.size();
}