#include <iostream>
using namespace std;
void sapxep(int o[],int t){
    for(int i=1;i<t;i++){
    	int x=o[i],pos=i-1;
    	while(pos>=0 && x<o[pos]){
    		o[pos+1]=o[pos];
    		--pos;
		}
		o[pos+1]=x;
	}
}
int a[1000];
int main(){
	int n;
	cin >> n;
	int p[n];
	int m=INT_MIN;
	for(int i=0;i<n;i++){
		cin >> p[i];
		a[p[i]]++;
		m=max(m,p[i]);
	}
	for(int i=0;i<=m;i++){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				cout << i << " ";
			}
		}
	}
}
