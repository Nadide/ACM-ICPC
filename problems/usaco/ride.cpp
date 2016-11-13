/*
ID: nadidep2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int f (string str) {
	int x = 1;
	for (int i=0; i < str.length(); i++)
		x = (x * (str[i]-'A'+1))%47;
	return x;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

	string commet, group;
	fin >> commet >> group;
	int cmod = f(commet);
	int gmod = f(group);
	fout << (cmod == gmod ? "GO" : "STAY") << endl;
    return 0;
}