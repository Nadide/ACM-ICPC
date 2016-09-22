#include <iostream>
#include <climits>
using namespace std;

int main ()
{
	int x,y,z,i,j;
	int v,e;

	cin >> v >> e;
	int g[v][v];
	for (int i=0; i<v; i++) {
		for (int j=0; j<v; j++)
			g[i][j] = g[j][i] = 0;
	}
      

	for (i=0; i<e; ++i) {
		cin >> x >> y >> z;
		g[x][y] = g[y][x] = z;
	}

	int parent[v];
	int key[v];
	bool used[v];
	for (int i=0; i<v; ++i)
		key[i]=INT_MAX, used[i]=false;

	key[0] = 0;
	parent[0] = -1;
	for (j=0; j < v-1; ++j) 
	{
		int min = INT_MAX, minI;
                for (i=0; i < v; ++i)
                        if (!used[i] && key[i]<min) 
                                min = key[i], minI = i;

		int u = minI;
                used[u] = true;
		for (i=0; i < v; ++i) 
			if (g[u][i] && !used[i] && g[u][i] < key[i]) 
				key[i] = g[u][i], parent[i] = u; 
	}

        cout << "Edge  Weight\n";
        for (int i=1; i < v; ++i)
                cout << parent[i] <<" - "<< i <<"   "<< g[i][parent[i]] << endl;
}
