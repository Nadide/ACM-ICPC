// TIMEOUT 1/3
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int a[10005];
int A[10005];

int comp (int *a, int *b) {
	return *a - *b;
}

int binarySearch (int low, int high, int key) {
    	if (low > high) return -1;

    	int mid = (low+high)/2;
	if (key == a[mid])
                return mid;
    	if (key < a[mid])
        	return binarySearch (low, mid, key);
    	if (key > a[mid])
        	return binarySearch (mid+1, high, key);
    
    	return -1;
}

int main() {
	int t,m,n,i,j,c;
    	scanf ("%d", &t);
    	while (t-- > 0) {
        	scanf ("%d %d", &m, &n);
        	for (i=0; i<n; i++) {
            		scanf ("%d", &a[i]);
			A[i] = a[i];
		}
 
       		qsort (a,n,sizeof(int),comp);
        	for (i=0; i<n-1; i++) {
			if (m-a[i] < 0) continue;
            		int x = binarySearch (i+1,n,m-a[i]);
            		if (x != -1) {
				for (j=0,c=0; j<n && c<2; j++) 
					if (A[j]==a[i] || A[j]==a[x]) {
                				printf ("%d ", j+1);
						c++;
					}
				printf ("\n");
                		break;
            		}
        	}
    	}
    
	return 0;
}

