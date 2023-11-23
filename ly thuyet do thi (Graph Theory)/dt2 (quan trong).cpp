//chuyen doi do thi
//chuyen doi do thi danh sach canh sang dt danh sach ke

#include <iostream>
#include <vector>
using namespace std;
int main(){
	//tao cac danh sach ke bang mang cac vector
	vector<int> p[1001];
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		//cho x vao danh sach ke cua y va y vao danh sach ke cua x
		p[x].push_back(y);
		p[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
	cout << i << ":";
	//duyet cac vector trong mang p
	    for(int j : p[i]){
	    	cout << j << " ";
		}
		cout << endl;
	}
}
