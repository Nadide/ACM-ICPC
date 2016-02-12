#include <stdio.h>
int okay;

fact (int n, int primes[], int nPr, int index, int result, int count)
{
	int i, j;
	printf ("index=%d  result=%d  count=%d\n", index, result, count);
	
	if (count == 2) {
		okay++;
		printf ("returned\n");
		return;
	}
		
	for (i=index; i<nPr; i++) {
		for (j=1; result*primes[i]*j <= n; j++) {
			fact (n, primes, nPr, i+1, result*primes[i]*j, count+1);
		}
	}
}

main ()
{
	int n, i, j;
	int primes[3005], nPr=0;	// bound = n
	int was[60]={0}; 		// bound = sqrt(n)

	scanf ("%d", &n);
	was[0] = was[1] = 1;
	for (i=2; i*i<=n; i++)
		if (was[i] == 0)
		{
			for (j=i*i; j<=n; j+=i)
				was[j] = 1;
		}

	for (i=2; i<=n; i++)
		if (was[i] == 0)
			primes[nPr++] = i;
	
/*	printf ("Prime list: ");
	for (i=0; i<nPr; i++)
		printf ("%d ", primes[i]);
	printf ("\n");
*/

	for (i=0; i<nPr; i++)
		fact (n, primes, nPr, i+1, primes[i], 1);	
	printf ("%d\n", okay);
}
