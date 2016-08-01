#include <stdio.h>
#include "cs50.h"
#define INF 0x7fffffff

int main(void)
{
    int n,min,s[3];
    int wait1,wait2,wait3;
    scanf ("%d", &n);
    int a[n];
    for (int i=0; i<n; i++)
        scanf ("%d", &a[i]);
    
    min = INF;
    wait1 = wait2 = wait3 = 0;
    for (int s1=1; s1<n-2; s1++) {
        for (int i=0; i<s1; i++)
                wait1+= a[s1]-a[i];
       
        for (int s2=s1+1; s2<n-1; s2++) {
            for (int i=s1+1; i<s2; i++)
                wait2+= a[s2]-a[i];
            
            for (int i=s2+1; i<n; i++)
                wait3+= a[n-1]-a[i];
            
            if ((wait1+wait2+wait3) < min) {
                min = wait1+wait2+wait3;
                s[0] = s1;
                s[1] = s2;
                s[2] = n-1;
            }
            
            wait2 = wait3 = 0;
        }
        wait1 = 0;
    }
    printf ("%d\n%d\n%d\n", a[s[0]],a[s[1]],a[s[2]]);
     
}

