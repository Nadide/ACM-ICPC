#include <iostream>
#include <climits>
using namespace std;

int main ()
{
	int x,y,z,i,j;
	int v,e;

	// Get inputs
	cin >> v >> e;
	int g[v][v];      
	for (i=0; i<e; ++i) {
		cin >> x >> y >> z;
		g[x][y] = g[y][x] = z;
	}

	// Assign initial values
	// Key - will be infinite
	// Used - not visited yet
	int parent[v];
	int key[v];
	bool used[v];
	for (int i=0; i<v; ++i)
		key[i]=INT_MAX, used[i]=false;

	int u = 0;
	used[u] = true;
	key[u] = 0;
	parent[u] = -1;
	for (j=0; j < v-1; ++j) 
	{
                for (i=0; i < v; ++i)
                        if (g[u][i] && !used[i] && g[u][i] < key[i])
                                key[i] = g[u][i], parent[i] = u;

		int min = INT_MAX, minI;
                for (i=0; i < v; ++i)
                        if (!used[i] && key[i]<min) 
                                min = key[i], minI = i;
		u = minI;
		used[u] = true;
	}

        cout << "Edge  Weight\n";
        for (int i=1; i < v; ++i)
                cout << parent[i] <<" - "<< i <<"   "<< g[i][parent[i]] << endl;
}
