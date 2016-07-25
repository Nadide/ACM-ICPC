#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<long int> a;
long int n,m,maxi,x;

int binary (int l, int r) {
    
    if (r-l == 1) { 
        if (a[l]%m > maxi) {
            printf ("a[l] %d\n",a[l]%m);
            maxi = a[l]%m;
        }
        return a[l]%m;
    }
    
    int p1 = binary (l, (l+r)/2);
    int p2 = binary ((l+r)/2, r);
    if ((p1+p2)%m > maxi) {
        printf ("p1-p2  %d\n",(p1+p2)%m);
        maxi = (p1+p2)%m;
    }
    return (p1+p2)%m;
}

int main() {
    int t;
    scanf ("%d", &t);
    while (t-- > 0) {
        scanf ("%d %ld", &n, &m);
        for (int i=0; i<n; i++) {
            scanf ("%ld",&x);
            a.push_back(x);
        }
    
        x = binary (0,n);
        if (x > maxi)
            maxi = x;
        printf ("%ld\n", maxi);
        maxi = 0;
    }
    return 0;
}

