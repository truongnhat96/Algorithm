//đồ thị có hướng
#include <bits/stdc++.h>
using namespace std;
int n,m,s;
vector<pair<int,int>> v[100001];

//nhập vào danh sách cạnh và lưu các đỉnh và trọng số vào mảng vector các cặp pair
//sau đó chuyển đổi sang danh sách kề
void input(){
	cin >> n >> m >> s;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		v[x].push_back({y,z});
	}
}

//khởi tạo số cực lớn (dương vô cùng) =INF
const int INF =1e9;

//xây dựng thuật toán dijkstra
void dijkstra(int s){
	vector<long long> d(n+1,INF);
	vector<bool> thamdinh(n+1,false);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	d[s]=0;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int> top=q.top();
		q.pop();
		int u=top.second;
		if(thamdinh[u]) continue;
		thamdinh[u]=true;
		
		for(auto it : v[u]){
			int v=it.first;
			int z=it.second;
			if(d[v] > d[u]+z){
				d[v]=d[u]+z;
				q.push({d[v],v});
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		cout << d[i] << ' ';
	}
}



int main(){
	input();
	dijkstra(s);
}