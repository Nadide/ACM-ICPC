#include <stdio.h>

int GCD (int a, int b)
{
	return b == 0 ? a : GCD (b,a%b); 
}

/* int GCD (int a, int b) 
{
	for (;;) {
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}
*/

int main ()
{
	int a, b;

	scanf ("%d %d", &a, &b);
	printf ("%d\n", GCD(a,b));
}
