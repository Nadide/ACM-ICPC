#include <iostream>
using namespace std;

int setBit (int x, int position)
{
	int mask = (1 << position);
	return (x | mask);
}

int clearBit (int x, int position) 
{
	int mask = (1 << position);
	return (x & ~mask);
}

int flipBit (int x, int position)
{
	int mask = (1 << position);
	return (x ^ mask);
}

bool checkPowerOfTwo (int x)
// check if power of two
{
	return (x & x-1) == 0;
}

int main ()
{
	// LEFT SHIFTING : multipying with two
	cout << (10 << 1) << " "; // 20
	cout << (5 << 1) << endl; // 10

	// RIGHT SHIFTING : dividing by two
	cout << (5 >> 1) << " "; // 5
	cout << (2 >> 1) << endl; // 2

	cout << setBit (10, 4) << " ";  // 10 + 16
	cout << setBit (5, 3) << endl; // 5 + 8

	cout << clearBit (10, 3) << " ";  // 10 - 8
	cout << clearBit (5, 0) << endl; // 5 - 1

	cout << flipBit (10, 1) << " ";  // 10 - 2 (1 -> 0)
	cout << flipBit (5, 1) << endl; // 5 + 2 (0 -> 1)

	cout << checkPowerOfTwo (8) << " "; // 1000 & 0111 -> 0000
	cout << checkPowerOfTwo (5) << endl;
}