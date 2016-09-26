#include <iostream>
using namespace std;

int main ()
{
	int r,c,count;
	int d[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

	cin >> r >> c;
	while (r && c) {
		char g[r][c];
		for (int i=0; i<r; ++i)
			cin >> g[i];

		for (int x=0; x<r; ++x) {
			for (int y=0; y<c; ++y) {
				count = 0;
				for (int k=0; k<8; ++k) 
					if (0<=x+d[k][0] && x+d[k][0]<r && 0<=y+d[k][1] && y+d[k][1]<c) 
						if (g[x+d[k][0]][y+d[k][1]] == '*') count++;
				if (g[x][y] == '.')
					cout << count << "";
				else
					cout << g[x][y] << "";

			}
			cout << endl;
		}
		cin >> r >> c;
	}

}
