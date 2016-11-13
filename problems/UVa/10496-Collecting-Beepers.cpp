#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int t,sX,sY,n,b[11][2];
int g[11][11], dp[11][1 << 11];

int tsp (int pos, int mask) {
	cout << pos << " " << mask << endl;
	if (mask == (1 << n)-1)	
		return dp[pos][0];
	if (dp[pos][mask] != -1)
		return dp[pos][mask];

	int ans = 2000000000;
	for (int next=0; next < n; next++)
		if (next!=pos && !(mask & (1 << next)))
			ans = min (ans, g[pos][next]+tsp(next, mask | (1 << next)));
	return dp[pos][mask] = ans;
}

int main () {
	cin >> t;
	while (t--) {
		cin >> sX >> sY;
		cin >> b[0][0] >> b[0][1];
		cin >> n;
		for (int i=1; i <= n; ++i)
			cin >> b[i][0] >> b[i][1];

		n++;
		for (int i=0; i < n; i++)
			for (int j=0; j < n; ++j)
				g[i][j] =  fabs(b[i][0] - b[j][0]) + fabs(b[i][1] - b[j][1]);

		memset(dp, -1, sizeof dp);
		int cevap = tsp(0, 1);
    	cout << "The shortest path has length " << cevap << endl;
	}
}