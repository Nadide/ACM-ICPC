// DYNAMIC PROGRAMING 
// Sums numbers between index l - index r in 1D array
#include <stdio.h>

main ()
{
	int n,l,r;
	int a[101];
	int d[101];
	
	scanf ("%d %d %d", &n,&l,&r);
	for (int i=0; i<n; ++i) 
		scanf ("%d", &a[i]);

	d[0] = a[0];
	for (int i=1; i<n; ++i)
		d[i] = d[i-1]+a[i];

	printf ("%d\n", d[r-1]-d[l-2]);

}
