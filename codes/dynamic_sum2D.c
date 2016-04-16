// DYNAMIC PROGRAMING 
// Sums numbers between two points in 2D array
#include <stdio.h>

main ()
{
	int i,j;
	int n,m,x1,x2,y1,y2;
	int a[101][101];
	int d[101][101];

	scanf ("%d %d", &n,&m);
	scanf ("%d %d %d %d", &x1,&y1,&x2,&y2);
	for (i=1; i<=n; ++i)
		for (j=1; j<=m; ++j)
			scanf ("%d", &a[i][j]);

	for (i=1; i<=n; ++i)
		for (j=1; j<=m; ++j)
			d[i][j] = d[i-1][j]+d[i][j-1]-d[i-1][j-1]+a[i][j];

	/*for (i=1; i<=n; i++) {
		for (j=1; j<=m; j++)
			printf ("%2d ",d[i][j]);
		printf ("\n");
	}*/
	
	printf ("%d\n", d[x2][y2] - d[x1-1][y2] - d[x2][y1-1] + d[x1-1][y1-1]);
			
}
