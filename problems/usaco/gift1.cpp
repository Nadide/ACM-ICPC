/*
ID: nadidep2
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np,x,n; 
    map<string,int> m;
    vector<string> v;
    string s,t; 

    fin >> np;
    for (int i=0; i < np; i++)
    	fin >> s, v.push_back(s);

    for (int i=0; i < np; i++) {
    	fin >> s >> x >> n;
    	for (int j=0; j < n; j++) {
    		fin >> t;
    		m[s] -= x/n;
    		m[t] += x/n;
    	}
    } 

	for(string it : v)
    	fout << it <<" "<< m[it] << endl;

    return 0;
}