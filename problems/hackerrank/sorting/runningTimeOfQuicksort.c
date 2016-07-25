#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
int *a, *b, n;
int iShift;
int qShift;

void insertSort () {
    int num, i, j;
    
    for (i=1; i<n; i++) {
        num = a[i];
        for (j=i-1; num<a[j] && j>=0; j--) {
            a[j+1] = a[j];
            iShift++;
        }
        a[j+1] = num;
    }
    
}

void swap (int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
    qShift++;
}

int partition (int l, int r) {
    int p = r-1;
    int w = l;
    for (int i=l; i<r; i++) {
        if (b[i] < b[p]) {
            swap (&b[i], &b[w]);
            w++; 
        }
    }
    swap (&b[w], &b[p]);
    return w;
}

void quickSort (int l, int r) {
    if (r-l <= 1) return;
    
    int p = partition (l,r);
    if (l < r) {
        quickSort (l, p);
        quickSort (p+1, r);
    }
}

int main() {
    scanf ("%d", &n);
    a = (int *) malloc (sizeof(int *) * n);
    b = (int *) malloc (sizeof(int *) * n);
    
    for (int i=0; i<n; i++) {
        scanf ("%d", &a[i]);
        b[i] = a[i];
    }
    
    insertSort ();
    quickSort (0,n);
    printf ("%d\n", iShift-qShift);
    
    return 0;
}

