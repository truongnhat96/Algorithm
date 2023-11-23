//chuyển ma trận kề sang danh sách cạnh
#include <bits/stdc++.h>
using namespace std;

//tạo mảng 2 chiều để lưu ma trận kề
int a[1001][1001];
int main(){
	int n;
	cin >> n;
	
	//sử dụng các cặp pair để in ra danh sách cạnh
	vector<pair<int,int>> v;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j] && i<j)
			  v.push_back({i,j});
		}
	}
	for(auto it : v){
		cout << it.first << " " << it.second << endl;
	}
}