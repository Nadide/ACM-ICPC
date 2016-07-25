#include <stdio.h>
#include <string.h>
enum {true, false} typedef bool;
char g[1001][1001],used[1001][1001];
char c[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
char s[15] = "ALLIZZWELL";
int a,b;
bool DONE=false;

void dfs (int x, int y, int sEnd) 
{
	if (sEnd == 10) {
		DONE = true;
		return;
	}
	if (s[sEnd] != g[x][y])
                return;

	for (int i=0; i<8; i++) {
		if (0<=x+c[i][0] && x+c[i][0]<a && 0<=y+c[i][1] && y+c[i][1]<b) {
			dfs (x+c[i][0],y+c[i][1],sEnd+1);
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
