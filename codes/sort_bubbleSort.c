#include <stdio.h>

void swap (int *a, int *b) 
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int main ()
{
	int n, a[101];

	scanf ("%d", &n);
	for (int i=0; i<n; i++)
		scanf ("%d", &a[i]);

	for (int i=0; i<n; i++)
		for (int j=0; j<n-1; j++)
			if (a[j] > a[j+1])
				swap(&a[j+1],&a[j]);

	for (int i=0; i<n; i++)
		printf ("%d ", a[i]);
	printf ("\n");
}
