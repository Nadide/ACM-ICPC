//Depth First Search 
#include <stdio.h>
int g[1001][1001];
int n, m, start, end;
int was[1001], reach;

DFS (int x)
{
	int i;
	printf ("%d ", x);

	was[x] = 1;
	if (x == end)
		reach = 1;
	for (i=1; i<=n; ++i)
		if (g[x][i]==1 && was[i]==0)
			DFS (i);
}

int main ()
{
	int i, j, a, b; 

	scanf ("%d %d", &n, &m);
	scanf ("%d %d", &start, &end);
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
	DFS (start);
	if (reach == 1)
		printf ("\nThere is a way\n");
	else 
		printf ("\nThere is no way\n");
}
