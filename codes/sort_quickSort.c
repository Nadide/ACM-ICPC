#include <stdio.h>

void swap (int a[], int i, int j) 
{
	int x = a[i];
        a[i] = a[j];  
        a[j] = x;
}

void qsort (int a[], int n)
{
	int pivot = n-1;
	int wall = 0;
	int current = 0;
	
	if (n <= 1) return; 
	
	for (; current < n; current++) {
		if (a[current] < a[pivot]) {
			swap (a,current,wall);
			wall++;
		}
	}
	swap (a,wall,pivot);

	// left part
	qsort (a, wall);
	
	// right part
	qsort (&a[wall+1], n-wall-1);
}

int main ()
{
	int n, a[1001];

	scanf ("%d", &n);
	for (int i=0; i<n; i++)
		scanf ("%d", &a[i]);

	qsort (a, n);	
	for (int i=0; i<n; i++)	
		printf ("%d ", a[i]);
	printf ("\n");
}
