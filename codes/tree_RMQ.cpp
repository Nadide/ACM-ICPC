// Range Minimum Query
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int query (int seg[], int qlow, int qhgh, int low, int hgh, int pos)
{
	if (qlow <= low  &&  hgh <= qhgh) return seg[pos];
	if (qhgh <  low  ||  hgh <  qlow) return INT_MAX;

	int mid = (low+hgh)/2;
	return min ( query(seg, qlow, qhgh, low, mid, 2*pos+1), // left-child
		query(seg, qlow, qhgh, mid+1, hgh, 2*pos+2) ); // right-child
}

void initialize (int ar[], int seg[], int low, int hgh, int pos) 
{
	if (low == hgh) {
		seg[pos] = ar[low];
 		return;
	}

	int mid = (low+hgh)/2;
	initialize (ar, seg, low, mid, 2*pos+1); // left-child
	initialize (ar, seg, mid+1, hgh, 2*pos+2); // right-child

	seg[pos] = min (seg[2*pos+1], seg[2*pos+2]);
}

int main ()
{
	int n,m; 	  
	cin >> n;
	int ar[n]; 
	for (int i=0; i<n; i++) 
		cin >> ar[i];
	
	m = (1 << (int)ceil(log2(n))) * 2 - 1;
	int seg[m]; 
	for (int i=0; i<m; i++)
		seg[i] = INT_MAX;

	int qlow,qhgh;
	cin >> qlow >> qhgh; 
	initialize (ar, seg, 0, n-1, 0);
	cout << query (seg, qlow, qhgh, 0, n-1, 0) << endl;
}
