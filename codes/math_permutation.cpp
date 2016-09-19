#include <iostream>
using namespace std;
int n,count,used[100000];

void perm (int a[], int per[], int d)
{
    	if (d == n)
    	{
        	count++;
        	for (int i=0; i<n; i++)
            		cout << per[i] << " ";
        	cout << endl;
        	return;
    	}
    
	for (int i=0; i<n; i++)
        	if (!used[i])
        	{
            		per[d] = a[i];
            		used[i] = 1;
            		perm (a, per, d+1);
            		used[i] = 0;
        	}
}

int main ()
{
    	cin >> n;
	int a[n], per[n];
    	for (int i=0; i<n; i++)
        	cin >> a[i];

    	perm (a, per, 0);
    	cout << count << endl;

    return 0;
}
