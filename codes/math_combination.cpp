#include <iostream>
using namespace std;
int n,m;

void comb (int a[], int com[], int d, int k)
{
    	if (d == m)
    	{
        	for (int i=0; i<m; i++)
            		cout << com[i] << " ";
        	cout << endl;
        	return;
    	}
    
	for (int i=k; i<n; i++)
    	{
        	com[d] = a[i];
        	comb (a, com, d+1,i+1);
    	}
}

int main ()
{ 
	cin >> n;
	int a[n],com[n];
    	for (int i=0; i<n; i++)
        	cin >> a[i];

    	for (m=1; m<=n; m++)
		comb (a,com,0,0);

    	return 0;
}
