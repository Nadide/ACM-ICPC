#include <iostream>
using namespace std;
int g[1001][1001],n,m;

void queen (int x, int y)
{
	int xx = x, yy = y;
	int d[8][2] = {{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1}};

	for (int i=0; i<8; ++i) { 
		x = xx, y = yy;
		while (0<=x+d[i][0] && x+d[i][0]<n && 0<=y+d[i][1] && y+d[i][1]<m 
			&& g[ x+d[i][0] ][ y+d[i][1] ]!=2) {
			g[x+d[i][0]][y+d[i][1]] = 1;
			x = x+d[i][0];
			y = y+d[i][1];
		}
	}
}

void knight (int x, int y)
{
	int d[8][2] = {{1,2},{2,1},{1,-2},{2,-1},{-1,-2},{-2,-1},{-2,1},{-1,2}};
	for (int i=0; i<8; ++i) 
		if (0<=x+d[i][0] && x+d[i][0]<n && 0<=y+d[i][1] && y+d[i][1]<m) 
			g[x+d[i][0]][y+d[i][1]] = 1;
}


int main ()
{
	int kk,x,y;
	int q[101][2],k[101][2];

	int board=1;
	cin >> n >> m;
	while (n && m) 
	{
		int qN, kN;
		cin >> qN;
		for (int i=0; i<qN; ++i) {
			cin >> x >> y;
			g[x-1][y-1] = 2;
			q[i][0] = x-1, q[i][1] = y-1;
		}

		cin >> kN;
		for (int i=0; i<kN; ++i) {
                        cin >> x >> y;
                        g[x-1][y-1] = 2;
			k[i][0] = x-1, k[i][1] = y-1;
                }

		cin >> kk;
		for (int i=0; i<kk; ++i) {
                        cin >> x >> y;
                        g[x-1][y-1] = 2;
                }

		for (int i=0; i<qN; ++i)
			queen (q[i][0], q[i][1]);
		
		for (int i=0; i<kN; ++i)
			knight (k[i][0], k[i][1]);
		
		int count=0;
		for (int i=0; i<n; ++i) 
			for (int j=0; j<m; ++j) { 
				if (!g[i][j]) count++;
				g[i][j] = 0;
			}

		cout << "Board " << board << " has " << count << " safe squares." << endl;
		cin >> n >> m;
		board++;
	}

}
