#include <stdio.h>

void swap (int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}

int partition(int ar[], int l, int r) {
    
    int new[1001], nC=0;
    for (int i=l+1; i<=r; i++) 
        if (ar[i] <= ar[l])
            new[nC++] = ar[i];
    int p = nC+l;
    new[nC++] = ar[l];
    for (int i=l+1; i<=r; i++)
        if (ar[i] > ar[l])
            new[nC++] = ar[i];
        
    for (int i=l; i<=r; i++)
        ar[i] = new[i-l];
    
    return p;
}

void qSort (int ar[], int l, int r) {
    
    if (r-l < 1) return;
    
    int p = partition (ar, l, r);    
    if (l < r) 
    {
        qSort (ar, l, p-1);
        qSort (ar, p+1, r);
    }
    
    for (int i=l; i<=r; i++)
        printf ("%d ", ar[i]);
    printf ("\n");
}

int main() {

    int size;
    scanf("%d", &size);
    int ar[1001];
    for(int i = 0; i < size; i++) 
        scanf("%d", &ar[i]);
    
    qSort (ar, 0, size-1);

    return 0;
}

