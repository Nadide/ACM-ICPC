#include <stdio.h>
#include "cs50.h"
char a[7]= "catkien";

void swap (char s[], int i, int j) {
    char k = s[i];
    s[i] = s[j];
    s[j] = k;
}

int in (char c) {
    for (int i=0; i<7; i++)
        if (c == a[i]) 
            return 1;
    return 0;
}

int main(void)
{
    int n,l,r;
    scanf ("%d", &n);
    char s[n];
    scanf ("%s", s);
    for (l=0,r=n-1; l < r; l++,r--) {
        while (l<r && in(s[l]) == 0) l++;
        while (l<r && in(s[r]) == 0) r--;
        swap (s, l, r);
    }
    printf ("%s", s);
    
    return 0;
}

