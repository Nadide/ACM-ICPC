// Noldbach problem
#include <stdio.h>

main ()
{
	int n, k, i, j;
	int primes[1000], nPr=0;	// bound n
	int was[40]={0};		// bound sqrt(n)
	int sum, count=0;

	scanf ("%d %d", &n, &k);
	was[0] = was[1] = 1;
	for (i=2; i*i<=n; i++) 
		if (was[i] == 0)
			for (j=i*i; j<=n; j+=i)
				was[j] = 1;

	for (i=2; i<=n; i++)
		if (was[i] == 0)
			primes[nPr++] = i;

	for (i=1; i<nPr; i++)
		if (was[1+primes[i]+primes[i+1]]==0 && 1+primes[i]+primes[i+1]<=n)
			count++;

	if (count >= k)
		printf ("YES\n");
	else
		printf ("NO\n");
} 
