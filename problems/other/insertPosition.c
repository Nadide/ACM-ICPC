/* 
*  Binary Search
*  Given a sorted array and a target value, return the index if the target is found. 
*  If not, return the index where it would be if it were inserted in order.
*  You may assume no duplicates in the array.
*/
#include <stdio.h>
#include <stdlib.h>
int *a, n;

int binarySearch (int low, int high, int key)
{
	if (high < low) return -1;			
	
	int mid = (low+high)/2;
	if (mid == 0)
		if (key < a[mid]) 
			return 0;
		else
			return -1;

	if (mid == n-1)
		if (key < a[high-1])
			return high-1;
		else
			return high;

	if (a[mid-1] < key && key < a[mid])
		return mid;
	
	if (key < a[mid])
		return binarySearch (low, mid, key);
	
	if (key > a[mid])	
		return binarySearch (mid+1, high, key);
}

int main () 
{
	int key;
	scanf ("%d %d", &n, &key);
	a = (int*) malloc(sizeof(int*) * n);
	for (int i=0; i<n; i++)
		scanf ("%d", &a[i]);

	printf ("%d\n", binarySearch (0,n,key));

	return 0;
}
