#include <bits/stdc++.h>
#include <vector>
#define MOD 1000000007
using namespace std;
// 100 number
vector<int> caplist[101];
int dp[1<<10+1][101];
int allmask;


int countWays (int mask, int i) {
	if (mask == allmask) return 1;
	if (i > 100) return 0;
	if (dp[mask][i] != -1) return dp[mask][i];

	long long int ways = countWays (mask, i+1);
	int size = caplist[i].size();

	for (int j=0; j < size; ++j) {
		if (mask & (1<<caplist[i][j])) continue;
		else 
			ways += countWays (mask | (1<<caplist[i][j]), i+1);
		ways %= MOD;
	}

	return dp[mask][i] = ways;
}

int main ()
{
	string temp, str;
	int n, x;
	cin >> n;
	for (int i=0; i < n; ++i) {
		getline (cin, str);
		stringstream ss(str);
		while (ss >> temp) {
			stringstream s(temp);
			//s << temp;
			s >> x;
			caplist[x].push_back(i);
		}
	}

	// set all n bits as 1
	allmask = (1 << n) -1;

	// initialize all dp as -1
	memset (dp, -1, sizeof(dp));

	// recursively count
	cout << countWays (0,1) << endl;

	return 0;
}
