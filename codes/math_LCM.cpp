// Euclid's Least Common Multiple Algorithm
#include <stdio.h>
#include <iostream>
#include <math.h>

int GCD (int a, int b)
{
	return b == 0 ? a : GCD(b,a%b);
}

int LCM (int a, int b)
{
	return (a * b) / GCD(fabs(a),fabs(b));
}

int main ()
{
	int a,b,lcm;

	scanf ("%d %d", &a, &b);

	lcm = LCM (a,b);
	printf ("%d\n", lcm); 
}
