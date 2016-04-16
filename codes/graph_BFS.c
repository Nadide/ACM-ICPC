//Breadth First Search
#include <stdio.h>
int g[1001][1001];
int n, m, start, end;
int was[1001], reach; 
int q[1001], qBgn, qEnd, node;

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
	node = start;
	was[node] = 1; 
	for (i=0; i<n-1; ++i) {
		printf ("%d ", node);
		for (j=1; j<=n; ++j)
			if (g[node][j] && !was[j])
				q[qEnd++] = j;
		node = q[qBgn++];
		//if we make it stack not queue "q[qEnd--]", it'll be DFS	
	
		was[node] = 1;
		if (node == end) {
			reach = 1;
			break;
		}
	}
	if (reach == 1)
		printf ("\nThere is a way\n");
	else
		printf ("\nThere is no way\n");

}
