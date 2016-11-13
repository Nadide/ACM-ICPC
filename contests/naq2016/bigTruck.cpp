// Djikstra's Shortest Path
// Shortest path from source to all vertices
#include <iostream>
#include <climits>
using namespace std;
int g[101][101],used[101],d[101],dT[101],t[101];

int main ()
{
	int n,m;
	int i,j,a,b,x;
	int min,current;

	cin >> n;
	for (i=1; i<=n; i++)
		cin >> t[i];
	
	cin >> m;
	for (i=0; i<m; ++i) {
		cin >> a >> b >> x;
		g[a][b] = g[b][a] = x;
	}

	current = 1;
	dT[1] = t[1];
	used[current] = 1;
	for (i=0; i<n; ++i) 
	{
		for (j=1; j<=n; ++j) 
			if (g[current][j] && !used[j])
				if (!d[j]) {
					d[j] = d[current]+g[current][j];
					dT[j] = dT[current]+t[j];
				} 
				else if (d[j] > d[current]+g[current][j]) {
					d[j] = d[current]+g[current][j];
					dT[j] = dT[current]+t[j];
				}
				else if (d[j] == d[current]+g[current][j]) {
					d[j] = d[current]+g[current][j];
					dT[j] = max (dT[j], dT[current]+t[j]);
				}

		min = INT_MAX;
		for (j=1; j<=n; ++j) {
			if (d[j] && !used[j])
				if (d[j] < min) {
					current = j;
					min = d[j];
				}
		}
		used[current] = 1;
	}

	if (d[n])
		cout << d[n] << " " << dT[n] << endl;
	else
		cout << "impossible" << endl;

	return 0;
}
