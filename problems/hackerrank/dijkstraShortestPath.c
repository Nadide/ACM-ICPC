#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 0X7FFFFFFF
int g[3005][3005];
int was[3005];
int d[3005];

int main() {
    int t,n,m,x,y,r,s,i,j;
    int node,min;
    
    scanf ("%d", &t);
    while (t-- > 0) {
        scanf ("%d %d", &n, &m);
        for (i=0; i<m; i++) {
            scanf ("%d %d %d", &x, &y, &r);
            if (!g[x][y] || r < g[x][y])
                g[x][y] = g[y][x] = r;
        }
        scanf ("%d", &s);
    
        node = s;
        was[node] = 1;
        for (i=0; i<n; i++) {
            for (j=1; j<=n; j++)
                if (g[node][j])
                    if (!d[j] || d[j] > d[node]+g[node][j]) 
                        d[j] = d[node]+g[node][j];
                    
            min = MAX;
            for (j=1; j<=n; j++) 
                if (d[j] && !was[j]) 
                    if (d[j] < min) {
                        min = d[j];
                        node = j;
                    }
            was[node] = 1;
        }
    
        for (i=1; i<=n; i++)
            if (i != s)
                if (d[i])
                    printf ("%d ", d[i]);
                else
                    printf ("-1 ");
        printf ("\n");
            
        for (i=1; i<=n; i++) {
            d[i] = was[i] = 0;
            for (j=1; j<=n; j++)
                g[i][j] = g[j][i] = 0;
        }
    }
    
    return 0;
}
