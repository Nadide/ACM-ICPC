#include <bits/stdc++.h>
using namespace std;

int main () 
{
    int a[] = {5,4,3,2,1};
    vector <int> b(a,a+5); //initialised b using elements of a. 
    sort(a,a+5);
    sort(b.begin(),b.end());
    for (auto i :a) {
        cout<<i<<" ";
    }
    cout<<endl;
    for (auto i:b) {
        cout<<i<<" ";
    }
    cout<<endl;
} 

