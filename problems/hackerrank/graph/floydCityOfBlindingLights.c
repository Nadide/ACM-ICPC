#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int g[405][405];
int d[405][405];

int main() {
    int n,m;
    int a,b,x;
    int i,j,k;
    scanf ("%d %d", &n, &m);
    for (i=0; i<m; i++) {
        scanf ("%d %d %d", &a, &b, &x);
        g[a][b] = x;
    }
    
    for (k=1; k<=n; k++)
        for (i=1; i<=n; i++)
            if (g[i][k])
                for (j=1; j<=n; j++)
                    if (g[k][j] && i!=j) 
                        if (!g[i][j] || g[i][j] > g[i][k]+g[k][j]) {
                            g[i][j] = g[i][k]+g[k][j];
                            d[i][j] = k;
                        }
    
    scanf ("%d", &x);
    while (x-- > 0) {
        scanf ("%d %d", &a, &b);
        if (g[a][b])
            printf ("%d\n", g[a][b]);
        else
            a == b ? printf("0\n") : printf("-1\n");
    }
    
                
    return 0;
}

