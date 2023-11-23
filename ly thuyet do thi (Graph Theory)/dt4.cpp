// chuyển ma trận kề sang danh sách kề
#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main(){
	int n;
	cin >> n;
	vector<int> v[1001];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			//kiểm tra nếu (i j) là 1 cạnh thì lưu j làm đỉnh kề vào mảng vector
		    if(a[i][j]){
		    v[i].push_back(j);
		    }
		}
	}
	for(int i=1;i<=n;i++){
	      cout << i <<  " : ";
	         for(int x : v[i]){
	         	cout << x << " ";
		  }
		  cout << endl;
	}
}
