#include <iostream>
using namespace std;
int main(){
	int n,x;
	cin >> n >> x;
	int p[n];
	for(int i=0;i<n;i++)
	cin >> p[i];
	auto it= lower_bound(p,p+n,x);
	cout << it-p;
}

