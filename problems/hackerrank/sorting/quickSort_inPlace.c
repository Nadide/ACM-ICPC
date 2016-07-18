#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n,a[5001]; 

void swap (int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int partition (int l, int r)
{
    int p = r-1;
    int w = l;
    for (int i=l; i<r; i++) {
        if (a[i] < a[p]) {
            swap (&a[w], &a[i]);
            w++;
        }
    }
    swap (&a[w], &a[p]);
    return w;
}

void quicksort (int l, int r)
{   
    if (r-l <= 1) return;
    
    int p = partition (l, r);
    for (int i=0; i<n; i++)
        printf ("%d ", a[i]);
    printf ("\n");
    
    if (l < r) {
        quicksort (l, p);
        quicksort (p+1, r);
    }
    
}

int main() {

    scanf ("%d", &n);
    for (int i=0; i<n; i++)
        scanf ("%d", &a[i]);
    quicksort (0, n);
    
    return 0;
}

