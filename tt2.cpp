#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
bool ok(int a,int b){
	return abs(a)<abs(b);
}
int main(){
	int n;
	cin >> n;
	int p[n];
	for(int i=0;i<n;i++)
	cin >> p[i];
	stable_sort(p,p+n,ok);
	for(int i=0;i<n;i++){
		cout << p[i] << " ";
	}
}
