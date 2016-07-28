#include <cstdio>
#include <iostream>
using namespace std;
char g[1001][1001],used[1001][1001];
char c[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
char s[15] = "ALLIZZWELL";
bool was[1001][1001],DONE=false;
int a,b;

void dfs (int x, int y, int sEnd) 
{
	if (s[sEnd] == '\0') {
		//printf ("x=%d y=%d sEnd=%d\n",x,y,sEnd);
		DONE = true;
		return;
	}
	if (s[sEnd] != g[x][y])
                return;

	for (int i=0; i<8; i++) {
		if (0<=x+c[i][0] && x+c[i][0]<a && 0<=y+c[i][1] && y+c[i][1]<b) {
			was[x+c[i][0]][] = true;
			dfs (x+c[i][0],y+c[i][1],sEnd+1);
			was[][] = false;
			if (DONE) return;	
		}
	}
}

int main ()
{
	int t,i,j;
	scanf ("%d",&t);
	while (t-- > 0) {
		scanf ("%d %d", &a, &b);
		for (i=0; i<a; i++)
			scanf ("%s", g[i]);
		
		for (i=0; i<a && !DONE; i++)
			for (j=0; j<b && !DONE; j++)
				dfs (i,j,0);
		DONE ? printf ("YES\n") : printf ("NO\n");
		DONE = false;
	}

	return 0;
}
