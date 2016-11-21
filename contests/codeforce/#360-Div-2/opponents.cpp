#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int present (string s) 
{
	int count=0;
	for (int i=0; i < s.length(); i++)
		if (s[i] == '1') count++;
	return count;
}

int main () 
{
	int n,d;
	int mx,day,all;
 	string s;
 	cin >> n >> d;

 	mx = day = 0;
	for (int i=0; i < d; i++) {
		cin >> s;
		if (present(s) == n) {
			mx = max(mx, day);
			day = 0;
		}
		else
			day++;
	}
	mx = max(mx, day);
	cout << mx << endl;
}