#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> convertToBinary(long long int );
int countOnesInBinary(vector<int> );

int main(int argc, char *argv[])
{
  long long int num;
  cout << "Decimal Number : ";	cin >> num;
  vector<int> bin = convertToBinary(num);
  int onesCount = countOnesInBinary(bin);
  cout << "Number of ones in " << num << " = " << onesCount;

  return 0;
}

vector<int> convertToBinary(long long int num)
{
  long long int debugInt = num;
  vector<int> binary;
  while (num > 0) {
	binary.push_back(num%2);
	num = num/2;
  }
  reverse(binary.begin(), binary.end());

  //DEBUG :
  cout << "dec(" << debugInt <<") = bin(";
  for (int i = 0; i < binary.size(); i++)
	cout << binary[i];
  cout << ")" << endl;

  return binary;
}

int countOnesInBinary(vector<int> bin)
{
  int count = 0;
  for (int i = 0; i < bin.size(); i++)
	if (bin[i] == 1) ++count;
  return count;
}