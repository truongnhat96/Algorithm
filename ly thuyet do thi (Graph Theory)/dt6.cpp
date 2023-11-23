//chuyển danh sách kề sang danh sách cạnh
#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main(){
	int n;
	cin >> n;
	cin.ignore();
	for(int i=1;i<=n;i++){
		string s,x;
		getline(cin,s);
		
		//tách các từ trong xâu sau đó thực hiện chuyển về dạng số (int)
		stringstream ss(s);
		while(ss >> x){
			a[i][stoi(x)]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j] && i<j)
			cout << i << " " << j <<endl;
		}
	}
}
// (*) có thể lưu vào vector các kiểu pair để duyệt danh sách cạnh