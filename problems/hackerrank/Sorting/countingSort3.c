#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
int *a, count[100];
char s[10];

int main() {
    int n, x, c=0;
    scanf ("%d", &n);
    a = (int *) malloc (sizeof(int *) * n);
    for (int i=0; i<n; i++) {
        scanf ("%d %s", &a[i], s);
        count[a[i]]++;
    }
    
    for (int i=0; i<100; i++) {
        c += count[i];
        printf ("%d ", c);
    }
    printf ("\n");
    
    return 0;
}

