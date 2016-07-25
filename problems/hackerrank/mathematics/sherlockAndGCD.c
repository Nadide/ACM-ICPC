#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int GCD (int a, int b) {
    if (a > b) 
        return b==0 ? a : GCD(b,a%b);
    else
        return a==0 ? b : GCD(a,b%a);
}

int binary (int a[], int l, int r) {
    if (r-l == 1) 
        return a[l];
    
    int p1 = binary (a,l,(l+r)/2);
    int p2 = binary (a,(l+r)/2,r);
    return GCD (p1,p2);
    
    
}

int main() {
    int t,n,i,j;
    int a[101],x;
    
    scanf ("%d", &t);
    while (t-- > 0) {
        scanf ("%d", &n);
        for (int i=0; i < n; i++)
            scanf ("%d", &a[i]);

        if (binary (a,0,n) == 1)
            printf ("YES\n");
        else
            printf ("NO\n");
    }
    
    
    return 0;
}

