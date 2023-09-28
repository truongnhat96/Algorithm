#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

//xay dung comparator cho sort
bool ok(int a,int b){
	return abs(a)<abs(b);
}
int main(){
	int n;
	cin >> n;
	int p[n];
	for(int i=0;i<n;i++){
		cin >> p[i];
		p[i]*=p[i];
	}
	//ham sap xep mang: sort
	sort(p,p+n); 
	for(int i=0;i<n;i++){
		cout << p[i] << " ";
	}
}
