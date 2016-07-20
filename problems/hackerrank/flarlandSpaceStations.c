#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int *d, *c, n, m;

int main(){
    int n, m, max=-1; 
    scanf("%d %d",&n,&m);
    d = (int*) malloc(sizeof(int*) * n);
    for (int i=0; i < n; i++) 
       d[i] = -1;
    c = (int*) malloc(sizeof(int*) * m);
    for(int i=0; i < m; i++) 
       scanf ("%d",&c[i]);
    
    
    for (int j=0; j < m; j++) {
        for (int i=c[j],x=0; (i>=0) && (d[i]==-1 || d[i]>=x);  i--,x++) d[i] = x;
        for (int i=c[j],x=0;  (i<n) && (d[i]==-1 || d[i]>=x);  i++,x++) d[i] = x;
    }
    
    for (int i=0; i<n; i++)
        if (d[i] >= max)
            max = d[i];
    printf ("%d\n", max);    
        
    return 0;
}

