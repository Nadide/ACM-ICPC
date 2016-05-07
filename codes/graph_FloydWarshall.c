// All Pairs Shortest Path by Floyd Warshall 
// Shortest path from every vertex to every other vertex
#include <stdio.h>
int g[101][101];
int d[101][101];

void way (int i, int j) 
{
	if (!d[i][j])
		return;

	int k = d[i][j];
	way (i,k);
	printf ("%d ", k);
	way (k, j);	

}

int main ()
{
	int n,m;
	int a,b,x;
	int i,j,k;
	
	scanf ("%d %d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf ("%d %d %d", &a, &b, &x);
		g[a][b] = g[b][a] = x;
	}

	for (k=1; k<=n; k++)
		for (i=1; i<=n; i++)
			if (g[i][k])
				for (j=1; j<=n; j++)
					if (g[k][j] && i!=j)
						if (!g[i][j] || g[i][j] > g[i][k]+g[k][j])
						{
							g[i][j] = g[i][k]+g[k][j];
							d[i][j] = k;
						}

	//Dynamic array
	/*for (i=1; i<=n; i++) {
		for (j=1; j<=n; j++)
			printf ("%d ", d[i][j]);
		printf ("\n");
	}*/

	printf ("1 ");
	if (d[1][n])
		way(1,n);
	printf ("%d\n",n);

}
