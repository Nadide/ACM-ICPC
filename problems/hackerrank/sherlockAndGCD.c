// Related Topics: Greatest Common Divisor
// Status : 15/19 : Wrong Answer
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

int main() {
    int t,n,i,j;
    int a[101],x;
    
    scanf ("%d", &t);
    while (t-- > 0) {
        scanf ("%d", &n);
        for (int i=0; i < n; i++)
            scanf ("%d", &a[i]);

        for (i=0; i < n; i++) { 
            for (j=i+1; j < n; j++) 
                if (a[i] != a[j])
                {
                    x = GCD (a[i],a[j]);
                    //printf ("%d %d  =  %d\n",a[i],a[j],GCD(a[i],a[j]));
                    if (x == 1)
                        break;
                }
            if (j != n) break;
        }
        if (i != n) 
            printf ("YES\n");
        else 
            printf ("NO\n");
    }
    
    
    return 0;
}

