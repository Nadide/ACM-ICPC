#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


void insertionSort(int size, int *  ar) {
    int e = ar[size-1];
    for (int i=size-1; i>=0; i--) {
        if (ar[i-1] > e) {
            ar[i] = ar[i-1];
        }
        else {
            ar[i] = e;
            for (int j=0; j<size; j++)
                printf ("%d ", ar[j]);
            printf ("\n");
            break;
        }
        for (int j=0; j<size; j++)
            printf ("%d ", ar[j]);
        printf ("\n");
        
    }
}

int main(void) {
    int size;
    scanf("%d", &size);
    int ar[size], _ar_i;
    for(_ar_i = 0; _ar_i < size; _ar_i++) { 
        scanf("%d", &ar[_ar_i]); 
    }

    insertionSort(size, ar);
    return 0;
}

