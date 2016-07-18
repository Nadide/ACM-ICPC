#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
int *a, count[100];
char **s, **out;

int main() {
    int n, x, i;
    scanf ("%d", &n);
    a = (int *) malloc (sizeof(int *) * n);  
    s = (char *) malloc (sizeof(char *) * n);
    out = (char *) malloc (sizeof(char *) * n);
    for (i=0; i<n; i++) {
        s[i] = (char *) malloc (sizeof(char *) * 10);
        out[i] = (char *) malloc (sizeof(char *) * 10);
    }

    for (i=0; i<n; i++) {
        scanf ("%d %s", &a[i], s[i]);
        count [a[i]]++;
    }
    
    for (i=98; i>=0; i--)
        count[i] += count[i+1];
    
    for (i=0; i<n; i++) {
        if (i < n/2)
            out[n-count[a[i]]] = "-";
        else
            out[n-count[a[i]]] = s[i];
        count[a[i]]--;
    }
    
    for (i=0; i<n; i++)
        printf ("%s ", out[i]);
    printf ("\n");
    
    return 0;
}

