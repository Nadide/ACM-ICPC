#include <stdio.h>

void swap (int ar[], int i, int j) {
    int x = ar[i];
    ar[i] = ar[j];
    ar[j] = x;
}

void partition(int size, int * ar) {
    int l,r,p;

    l = 1;
    r = size-1;
    p = ar[0];
    while (l < r) {
        while (ar[l] <= p) l++;
        while (ar[r] >= p) r--;
        if (l < r)
            swap (ar,l,r);
    }
    swap (ar, 0, l-1);

    for (int i=0; i<size; i++)
        printf  ("%d ", ar[i]);
    printf ("\n");
}

int main(void) {

    int size;
    scanf("%d", &size);
    int ar[size];
    for(int i = 0; i < size; i++) {
        scanf("%d", &ar[i]);
    }

    partition(size, ar);

    return 0;
}

