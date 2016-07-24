#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
char **g;

int main ()
{
	int n,m;
	int a,b,i,j;
	char c;
	g = (char*) malloc (sizeof(char*)*n);
	for (i=0; i<n; i++)
		g[i] = (char*) malloc (sizeof(char*)*n);	

	scanf ("%d %d", &n, &m);
	for (i=0; i<n; i++) {
		scanf ("%d %d %c", &a,&b,&c);
		g[a][b] = g[b][a] = c;
	}
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++)
			printf ("%c ", g[i][j]);
		printf ("\n");
	}
	

	return 0;
}
