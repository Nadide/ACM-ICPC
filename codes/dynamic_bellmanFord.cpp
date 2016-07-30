#include <cstdio>
#include <vector>
#define INF 0x7fffffff
using namespace std; 

struct edge {
	// previous, next, weight
	int prev,next,w;
} typedef edge;

int main ()
{
	int n,m,s;
	int a,b,x;
	scanf ("%d %d", &n, &m);
	
	edge edges[m];
	for (int i=0; i<m; i++) {
		scanf ("%d %d %d", &a, &b, &x);
		edges[i].prev = a;
		edges[i].next = b;
		edges[i].w = x;
	}
	scanf ("%d", &s);		
	
	int dist[n];
	for (int i=1; i<=n; i++)
		(i == s) ? dist[i]=0 : dist[i]=INF ;
	
	for (int i=0; i<n-1; i++) 
		for (int j=0; j<m; j++) {
			int prev = edges[j].prev;
			int next = edges[j].next;
			int w = edges[j].w;
			if (dist[prev]!=INF && dist[prev]+w < dist[next])
				dist[next] = dist[prev]+w;
		}

	for (int i=1; i<=n; i++)
		if (dist[i] == INF)
			printf ("INF ");
		else
			printf ("%d ", dist[i]);
	printf ("\n");

}
