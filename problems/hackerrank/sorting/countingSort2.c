#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
int *a, count[101];

int main() {
    int n, x;
    scanf ("%d", &n);
    a = (int *) malloc (sizeof(int *) * n);
    for (int i=0; i<n; i++) { 
        scanf ("%d", &a[i]);
        count[a[i]]++;
    }

    for (int i=0; i<100; i++)
        for (int j=0; j<count[i]; j++)
            printf ("%d ", i);
    printf ("\n");
    
    return 0;
}


