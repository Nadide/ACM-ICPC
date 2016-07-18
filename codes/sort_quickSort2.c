#include <stdio.h>

void swap (int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int partition (int a[], int l, int r)
{
	int p = r-1;    //pivot
	int w = l-1;	//wall
	for (int i=l; i<r-1; i++)  //current
		if (a[i] < a[p])
			swap (&a[++w], &a[i]);
	swap (&a[w+1], &a[p]);
	return w+1;	
}

void qSort (int a[], int l, int r)
{
	if (l < r)
	{
		int p = partition (a, l, r);
		qSort (a, l, p);
		qSort (a, p+1, r);
	}

}

int main ()
{
	int n,a[101];

	scanf ("%d", &n);
	for (int i=0; i<n; i++)
		scanf ("%d", &a[i]);

	qSort (a, 0, n);

	for (int i=0; i<n; i++)
		printf ("%d ", a[i]);
	printf ("\n");

}
