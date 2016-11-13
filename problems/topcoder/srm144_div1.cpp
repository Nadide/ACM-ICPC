#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main ()
{
	// p-original, q-decoded
	int p[55], q[55];

	string message;
	cin >> message;
	for (int i=0; i < message.size(); i++)
		q[i] = message[i]-'0';

	vector<string> result;
	for (int x=0; x <= 1; x++) 
	{
		bool exist = true;
		p[0] = 0,  p[1] = x;
		for (int i=2; i < message.size()+1; i++) {
			p[i] = q[i-2] - p[i-1] - p[i-2];
			if (p[i] < 0 || p[i] > 1) {
				exist = false;
				break;
			}
		}

		if (exist) {
			stringstream s;
			for (int i=1; i < message.size()+1; i++)
				s << p[i];
			result.push_back(s.str());
		}
		else
			result.push_back("NONE");
	}

	cout << result[0] << endl << result[1] << endl;
}



// if (n == 1) {
// 		if (message[0] == '0')
// 			result.push_back("0"), result.push_back("NONE");
// 		else
// 			result.push_back("NONE"), result.push_back("1");
// 		//return result;
// 	}
// else

// if (q[message.size()] = p[message.size()-1]+)