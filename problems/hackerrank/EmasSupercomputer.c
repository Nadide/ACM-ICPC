// no response on stdout !?
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n, m;
char **g, **u;  // grid, used

int plus (int x, int y, int deep) {
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int ee,ww,nn,ss,unit=1,max=0;
    
    if (deep == 3) return 0;
    printf ("x=%d y=%d deep=%d\n",x,y,deep);
    
    u[x][y] = 1;
    ee = ww = x;
    nn = ss = y;
    while ( 0<=ww+d[0][0] && ee+d[0][1]<n && 0<=nn+d[1][0] && ss+d[1][1]<m &&
          !u[ww+d[0][0]] && !u[d[0][1]] && !u[nn+d[1][0]] && !u[ss+d[1][1]] ) {
        unit += 4;
        ee += d[0][0]; u[ee][y]=1;
        ww += d[0][1]; u[ww][y]=1;
        nn += d[1][0]; u[x][nn]=1;
        ss += d[1][1]; u[x][ss]=1;
    }
    
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (!(i==x && j==y)) {
                int p = unit + plus(i,j,deep+1);
                if (p > max)
                    max = p;
            }
            u[x][y] = 0;
            ee = ww = x;
            nn = ss = y;
            while ( 0<=ww+d[0][0] && ee+d[0][1]<n && 0<=nn+d[1][0] && ss+d[1][1]<m ) {
                ee += d[0][0]; u[ee][y]=0;
                ww += d[0][1]; u[ww][y]=0;
                nn += d[1][0]; u[x][nn]=0;
                ss += d[1][1]; u[x][ss]=0;
            }
        
        }
    
    return max;
}

int main() {
    int i, j, max=0;
    
    scanf ("%d %d", &n, &m);
    g = (char**) malloc(sizeof(char**) * n);
    u = (char**) malloc(sizeof(char**) * n);
    for (i=0; i < n; i++) { 
        g[i] = (char*) malloc(sizeof(char*) * m);
        u[i] = (char*) malloc(sizeof(char*) * m);
    }
    for (i=0; i < n; i++)
        scanf ("%s", g[i]);
  
    for (i=0; i < n; i++) {
        for (j=0; j < m; j++) {
            int p = plus (i, j, 1);
            if (p > max)
                max = p;
        }
    }
    printf ("%d\n", max);
    
    
    return 0;
}

