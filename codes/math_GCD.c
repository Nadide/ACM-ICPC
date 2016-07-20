// Euclid's Greatest Common Division Algorithm
#include <stdio.h>
#include <stdlib.h>


int GCD (int a, int b)
{
	return b == 0 ? a : GCD (b,a%b); 
}

/*int GCD (int a, int b) 
{
	for (;;) {
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}*/


int main ()
{
	int a,b,gcd;
	scanf ("%d %d", &a, &b);

	gcd = abs(a) > abs(b) ? GCD(a,b) : GCD(b,a);
	printf ("%d\n", abs(gcd));
}
