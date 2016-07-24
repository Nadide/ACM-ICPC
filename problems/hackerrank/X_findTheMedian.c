#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int *a, n, med;

void swap (int i, int j) {
    int x = a[i];
    a[i] = a[j];
    a[j] = x;
}

int part (int l, int r) {
    int p = r-1;
    int w = l;
    for (int i=l; i<r; i++) {
        if (a[i] < a[p]) {
            swap (w, i);
            w++;
        }
    }
    swap (w, p);
    return w;
}

void quicksort (int l, int r) {
    if (r-l < 1) return;
    
    int p = part (l,r);
    if (p == n/2) {
        med = a[p];
        return;
    }
    
    if (l < r) {
        //quicksort (l,p);
        //quicksort (p+1,r);
        (p-l) > (r-(p+1)) ? quicksort (l,p) : quicksort (p+1,r);
    }
}

int main() {
    scanf ("%d", &n);
    a = (int *) malloc (sizeof(int *) * n);
    for (int i=0; i<n; i++)
        scanf ("%d", &a[i]);
    
    quicksort (0,n);
    printf ("%d\n", med);
    
    return 0;
}

