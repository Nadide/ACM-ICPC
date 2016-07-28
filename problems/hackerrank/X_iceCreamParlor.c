#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int a[10005],A[10005],count[10001];

int comp (const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int binarySearch (int low, int high, int key) {
    if (low > high) return -1;
    
    int mid = (low+high)/2;
    if (key == a[mid])
        return mid;
    if (key < a[mid])
        return binarySearch (low, mid-1, key);
    if (key > a[mid])
        return binarySearch (mid+1, high, key);
    
    return -1;
}

int main() {
    int t,m,n,i;
    int max=0;
    scanf ("%d", &t);
    while (t-- > 0) {
        scanf ("%d %d", &m, &n);
       
        for (i=0; i<n; i++) {
            scanf ("%d", &A[i]);
            count[A[i]]++;
            if (A[i] > max)
                max = A[i];
        }
        
        // Sort
        for (i=1; i<=max; i++)
            count[i] += count[i-1];
        for (i=0; i<n; i++) {
            a[count[A[i]]-1] = A[i];
            count[A[i]]--;
        }
        
        // Search
        for (i=0; i<n; i++) {
            int x = binarySearch (i+1,n,m-a[i]);
            if (x != -1) {
                //count[a[i+1]]  count[a[x+1]]
                printf ("%d %d\n", i+1, x+1);
                break;
            }
        }
        
        
        for (i=0; i<=max; i++)
            count[i]=0;
        max=0;
    }
    return 0;
}
