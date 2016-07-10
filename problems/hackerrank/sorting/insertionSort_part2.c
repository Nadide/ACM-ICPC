#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(int size, int *ar) {

    for (int i=1; i<size; i++) 
    {
        if (ar[i-1] > ar[i]) 
        {
            for (int j=0; j<i; j++) 
                if (ar[i] <= ar[j]) {
                    int x= ar[i];
                    for (int k=i; k>j; k--)
                        ar[k] = ar[k-1];
                    ar[j] = x;
                    break;
                }
        }
        for (int j=0; j<size; j++)
            printf ("%d ",ar[j]);
        printf ("\n");
    }

}


int main(void) {
   
    int size;
    scanf("%d", &size);
    int ar[size], _ar_i;
    for(_ar_i = 0; _ar_i < size; _ar_i++)
        scanf("%d", &ar[_ar_i]); 
   
    insertionSort(size, ar);
   
   return 0;
}

