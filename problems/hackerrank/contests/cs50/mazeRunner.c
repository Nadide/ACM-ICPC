// DFS
#include <stdio.h>
#include "cs50.h"
string a[1001];
char was[1001][10001];
int n,m;

struct Cord { 
    int x,y; 
} typedef Cord;
Cord w[4]={{0,1},{0,-1},{1,0},{-1,0}}; //Coordinate
Cord bgn,end; 

void dfs (Cord pos, Cord way[], int wEnd) 
{   
    if (pos.x == end.x && pos.y == end.y) {
        way[wEnd].x = pos.x;
        way[wEnd].y = pos.y;
        for (int i=0; i<=wEnd; i++)
            if (i%2) printf ("[%d, %d]\n", (way[i].x)/2, (way[i].y)/2);
        return;
    }
    
    way[wEnd].x = pos.x;
    way[wEnd].y = pos.y;
    was[pos.x][pos.y] = 1;
    for (int i=0; i<4; i++) {
        Cord next = {(pos.x + w[i].x) , (pos.y + w[i].y)};
        if (0<=next.x && next.x<=n-1 && 0<=next.y && next.y<=m-1) 
            if (a[next.x][next.y] == ' ' && !was[next.x][next.y]) 
                    dfs (next, way, wEnd+1);
            
    }
    way[wEnd].x = 0;
    way[wEnd].y = 0;
    was[pos.x][pos.y] = 0;    
}

int main ()
{
    string x;
    do {
        x = GetString();
        a[n] = x;
    } while(a[n++] != '\0');
    n--;
    m = strlen(a[0]);
    
    Cord way[n*m];
    bgn.x = 0;
    bgn.y = 1;
    end.x = n-1;
    end.y = m-2;
    dfs (bgn, way, 0);
}
