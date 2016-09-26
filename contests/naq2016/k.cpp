#include <iostream>
using namespace std;

int main ()
{
	int t;
	int aa1,aa2,ll1,ll2,aaT,llT;
	int a1, a2, l1, l2, aT, lT;
	int x, y;
	cin >> t;
	while (t--) {
		cin >> ll1 >> aa1 >> ll2 >> aa2 >> llT >> aaT;	
		l1 = ll1*aa1, l2 = ll2*aa1, lT = llT*aa1;
		a1 = aa1*ll1, a2 = aa2*ll1, aT = aaT*ll1;
	
		if ((l2-a2) && l1 && !( (lT-aT) % (l2-a2) ) && !( (lT-l2*y) % l1 ))
		{
			y = (lT-aT)/(l2-a2);
			x = (lT-l2*y)/l1;
			cout << x <<" "<< y << endl;
		}
		else
			cout << "?" << endl;
	}

}
