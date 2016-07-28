// Modular Exponentiation (Power in Modular Aritmetic) (x^y)
#include <stdio.h>
#define M 100000007

int main ()
{
	long long int x,y,res=1;
	scanf ("%lld %lld", &x, &y);
	x = x%M;
	while (y > 0) {
		if (y%2) 
			res = (res*x)%M;
		y = y/2;
		x= (x*x)%M; 
	}
	printf ("%lld\n", res);

	return 0;
}
