#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int n1,n2;
	cin >> n1 >> n2;

	if (n2 < n1) n2+= 360;
	if ((n2-n1) <= (360-(n2-n1)))
		cout << (n2-n1) << endl;
	else
		cout << -(360-(n2-n1)) << endl;

}
