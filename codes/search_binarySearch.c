#include <stdio.h>
#include <stdlib.h>
int array[1001];

int compare (int *a, int *b) {
	return *a-*b;
}

int binSearch (int min, int max, int key)
{
	int mid = (min+max)/2;
	
	if (array[mid]==key)
		return mid;
	else if (max < min)
		return -1;
	
	if (key < array[mid])
		binSearch (min, mid-1, key);
	else if (key > array[mid])
		binSearch (mid+1, max, key);
}

int main ()
{
	int n, i, key;

	scanf ("%d %d", &n, &key);
	for (i=0; i<n; i++)
		scanf ("%d", &array[i]);
	qsort (array, n, sizeof(int), compare);

	printf ("Array in order: ");
	for (i=0; i<n; ++i)
		printf ("%d ", array[i]);
	printf ("\nPosition of key: ");
	printf ("%d\n", binSearch (0, n, key));
}
