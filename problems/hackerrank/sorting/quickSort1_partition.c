#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void partition(int size, int * ar) {
    int l[1001],r[1001],p = ar[0];
    int lC=0, rC=0;
    for (int i=1; i<size; i++) {
        if (ar[i] < p)
            l[lC++] = ar[i];
        if (p < ar[i])
            r[rC++] = ar[i];
    }
    for (int i=0; i<lC; i++)
        printf ("%d ", l[i]);
    printf ("%d ", p);
    for (int i=0; i<rC; i++)
        printf ("%d ", r[i]);
    printf ("\n");
        
}

int main(void) {
    int size;
    scanf("%d", &size); 
    int ar[size], _ar_i;
    for(_ar_i = 0; _ar_i < size; _ar_i++) { 
        scanf("%d", &ar[_ar_i]); 
    }

    partition(size, ar);
   
    return 0;
}

