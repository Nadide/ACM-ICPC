#include <stdio.h>

int GCD (int a, int b)
{
	if (a==0 || b==0)
		return a+b;
	if (a>b)
		return GCD(a%b, b);
	if (b>a) 
		return GCD(a, b%a);
}

int main ()
{
	int a, b;

	scanf ("%d %d", &a, &b);
	printf ("%d\n", GCD(a,b));
}
