#include <stdio.h>
int was[3001], primes[60];
int nPr;


void almostPrime ()
{
	int i;

	
}

main ()
{
	int n, i;
	
	scanf ("%d", &n);

	//find all primes	
	was[0] = was[1] = 1;
	for (i=2; i*i<=n; ++i)
		if (was[i] == 0)
			for (j=i*i; j<=n; j+=i)
				was[j] = 1;
	for (i=2; i<=n; ++i)
		if (was[i] == 0)
			primes[nPr++] = i;

	for (i=0; i<nPr; i++)
		almostPrime (1, 1, i);
		// result, deep, index

}
