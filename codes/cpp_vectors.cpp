#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	vector<int> vec;
	cout << "Vector size: " << vec.size() << endl;

	for (int i=0; i<5; ++i)
		vec.push_back(i*10);
	cout << "Extended vector size: " << vec.size() << endl;

	for (int i=0; i<vec.size(); ++i)
		cout << "Vec[" << i <<  "] = " << vec[i] << endl; 

	vector<int>::iterator v = vec.begin();
	while (v != vec.end()) {
		cout << "V = " << *v << endl;
		v++;
	}

	return 0;
}
