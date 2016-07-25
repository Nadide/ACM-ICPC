#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int g[1005][1005],n,m,s;
int q[1005],qBgn,qEnd; // queue
int p[1005],pBgn,pEnd; // parent q
int c[1005],was[1005];


int main() {
    int t,a,b,i,j,node;
    
    scanf ("%d", &t);
    while(t-- > 0) 
    {
        scanf ("%d %d", &n, &m);
        for (i=0; i<m; i++) {
            scanf ("%d %d", &a, &b);
            g[a][b] = g[b][a] = 6;
        }
        scanf ("%d", &s);
        
        node = s;
        was[node] = 1;
        c[node] = 0;
        
        for (i=0; ; i++) {
            for (j=1; j<=n; j++) 
                if (g[node][j] && !was[j]) {
                    q[qEnd++] = j;
                    p[pEnd++] = node;
                    was[j] = 1;
                }
           
            node = q[qBgn++];
            c[node] = c[p[pBgn++]]+6;
            if (qBgn > qEnd) break;
        }
        
        for (i=1; i<=n; c[i]=0,i++)
            if (i != s)
                if (c[i])
                    printf ("%d ", c[i]);
                else
                    printf ("-1 ");
        printf ("\n");
        
	for (i=0; i<qEnd; i++)
		q[i] = p[i] = 0;         
        for (i=1; i<=n; i++) {
            was[i] = c[i] = 0;
            for (j=1; j<=n; j++)
                g[i][j] = g[j][i] = 0;
        }
        qBgn = qEnd = 0;
        pBgn = pEnd = 0;
    }
    
    return 0;
}

