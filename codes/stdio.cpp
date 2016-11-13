#include <cstdio>

int main () {
	int a,b;
	char c,str[10];

	//printf ("scanf  = %d\n", scanf ("%d %s", &a, str));
	//printf ("printf = %d\n", printf ("%s : %d\n", str, a));

	//scanf ("%*d %d", &b);	// ignore first
	//printf ("b = %d\n", b);

	printf ("%d\n", scanf("%s", str));
	printf ("%s\n", str);

	//scanf ("0.%d...", &b);
	//printf ("b = %d\n", b);
}