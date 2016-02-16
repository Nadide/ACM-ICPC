#include <stdio.h>

int main ()
{
	int n, m;
	int a, b, x, i, j;
	int g[1001][1001];

	scanf ("%d %d", &n, &m);
	for (i=0; i<m; ++i) {
		scanf ("%d %d %d", &a, &b, &x);
		g[a][b] = x;
	}

	for (i=1; i<=n; ++i) { 
		for (j=1; j<=n; ++j)
			printf ("%d ", g[i][j]);
		printf ("\n");
	}
}
