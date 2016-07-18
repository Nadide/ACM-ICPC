#include <stdio.h>
#include <malloc.h>
int *a, *out, count[100];

int main ()
{
	int n, x, i;
	scanf ("%d", &n);
	a = (int *) malloc (sizeof(int *) * n);
	out = (int *) malloc (sizeof(int *) * n);
	for (i=0; i<n; i++) {
		scanf ("%d", &a[i]);
		count[a[i]]++;
	}
	
	for (i=1; i<100; i++)
		count[i] += count[i-1];

	for (i=0; i<n; i++) {
		out[count[a[i]]-1] = a[i];
		count[a[i]]--;
	}

	for (i=0; i<n; i++)
		printf ("%d ", out[i]);
	printf ("\n");	
	
	return 0;
}
