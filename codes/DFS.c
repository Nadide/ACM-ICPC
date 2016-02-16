#include <stdio.h>
int g[1001][1001];
int n, m, begin, end;
int was[1001], reach;

DFS (int x)
{
	int i;
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
	scanf ("%d %d", &begin, &end);
	for (i=0; i<m; ++i) {
		scanf ("%d %d", &a, &b);
		g[a][b] = 1;
	}

	/*for (i=1; i<=n; i++,printf("\n"))
		for (j=1; j<=n; j++)
			printf ("%d ", g[i][j]);
	*/

	DFS (begin);
	if (reach == 1)
		printf ("There is way\n");
	else 
		printf ("There is no way\n");
}
