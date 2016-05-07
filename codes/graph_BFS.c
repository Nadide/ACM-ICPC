//Breadth First Search
#include <stdio.h>
int g[1001][1001],n,m;
int was[1001],q[1001];
int qBgn, qEnd, node;

int main ()
{
	int i, j, a, b;

	scanf ("%d %d", &n, &m);
	for (i=0; i<m; ++i) {
		scanf ("%d %d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}

	/*PATHS
	for (i=1; i<=n; ++i,printf("\n"))
		for (j=1; j<=n; ++j)
			printf ("%d ", g[i][j]);
	*/

	printf ("Route: ");
	node = 1;
	was[node] = 1; 
	for (i=0; i<n-1; ++i) {
		printf ("%d ", node);
		for (j=1; j<=n; ++j)
			if (g[node][j] && !was[j])
				q[qEnd++] = j;
		node = q[qBgn++];
		//if we make it stack not queue "q[qEnd--]", it'll be DFS	
	
		was[node] = 1;
		if (node == n)
			break;
	}
	printf ("%d\n", node);

}
