#include <iostream>
using namespace std;


int main ()
{
	// first,total,pattern
	int n,m,k,p[1005],pN,pI,sN,i;
	
	cin >> n >> m >> k;
	while (n && m && k) {
		for (pN=0; pN<k; ++pN)
			cin >> p[pN];

		pI = 0;
		sN = n;
		for (i=1; i<m; ++i) {
			n += p[pI];
			sN += n;
			pI = (pI+1)%pN;
		}
		cout << sN << endl;
		cin >> n >> m >> k;
	} 
}
