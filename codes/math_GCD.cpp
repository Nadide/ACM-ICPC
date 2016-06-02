// Euclid's Greatest Common Division Algorithm
#include <cstdio>
#include <cstdlib>


int GCD (int a, int b) 
{
	return b == 0 ? a : GCD(b,a%b) ;
}

int main ()
{
	int a,b,gcd;
	scanf ("%d %d", &a, &b);
	gcd = abs(a) > abs(b) ? GCD(a,b) : GCD(b,a);
	printf ("%d\n", gcd);
}
