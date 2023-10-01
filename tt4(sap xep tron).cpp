#include <iostream>
#include <vector>
using namespace std;
void sapxep(int a[],int m,int l,int r){
	vector<int> x(a+l,a+m+1);
	vector<int> y(a+m+1,a+r+1);
	int i=0,j=0;
	while(i<x.size() && j<y.size()){
		if(x[i]<=y[j]){
			a[l]=x[i];
			++l;
			++i;
		}else{
			a[l]=y[j];
			++l;
			++j;
		}
	}
	while(i<x.size()){
		a[l]=x[i];
		++l;
		++i;
	}
	while(j<y.size()){
		a[l]=y[j];
		++l;
		++j;
	}
}

// su dung ham de quy
void sapxeptron(int a[],int l,int r){
	if(l>=r)
	return;
	int m=(l+r)/2;
	sapxeptron(a,l,m);
	sapxeptron(a,m+1,r);
	sapxep(a,m,l,r);
}
int main(){
	int n;
	cin >> n;
	int p[n];
	for(int i=0;i<n;i++){
		cin >> p[i];
	}
	int l=0,r=n-1;
	sapxeptron(p,l,r);
	for(int i=0;i<n;i++){
		cout << p[i] << " ";
	}
}
