//Depth First Search 
#include <stdio.h>
int g[1001][1001],n,m;
int was[1001];

void DFS (int x)
{
	int i;
	printf ("%d ", x);

	was[x] = 1;
	for (i=1; i<=n; ++i)
		if (g[x][i]==1 && was[i]==0)
			DFS (i);
}

int main ()
{
	int i, j, a, b; 

	scanf ("%d %d", &n, &m);
	for (i=0; i<m; ++i) {
		scanf ("%d %d", &a, &b);
		g[a][b] = 1;
	}

	/*PATHS 
	for (i=1; i<=n; ++i,printf("\n"))
		for (j=1; j<=n; ++j)
			printf ("%d ", g[i][j]);
	*/

	printf ("Route: ");
	DFS (1);
	printf ("\n");
}
