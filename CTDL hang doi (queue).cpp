//ứng dụng ctdl hàng đợi (queue)
//bài 1: liệt kê các số dạng nhị phân từ 1 -> n
//bài 2: biến đổi từ số s thành số t với 2 thao tác, giảm đi 1 đơn vị hoặc nhân s lên 2 lần 

/* - CTDL hàng đợi thường áp dụng cho các bài toán thường dc biểu diễn dưới dạng
   cây nhị phân
   - thường dùng trong các bài từ 1 số chuyển sang số khác, số dạng khác hoặc
     chuyển sang trạng thái khác 
   - các bài liên quan đến tìm bước di chuyển ít nhất
*/

#include <bits/stdc++.h>
using namespace std;


        /* bước di chuyển theo để bài cho phép trên đồ thị dx[], dy[]
	->	                 i-1,j
	->			i,j-1	 [i,j]     i,j+1
	->			         i+1,j  
		*/
int p[1000][1000];

int d[1000][1000]; 
//mảng để lưu số bước đi tối thiểu từ ô start(s) -> ô hiện tại đang xét

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
pair<int,int> s,e;
int n,m;

void nhap(){
	cin >> n >> m >> s.first >> s.second >> e.first >> e.second;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> p[i][j];
		}
	}
	memset(d,0,sizeof(d));
}

int giai(){
	queue<pair<int,int>> q;
	p[s.first][s.second]=0;
	q.push({s.first,s.second});
	
	while(!q.empty()){
		pair<int,int> top=q.front();
		q.pop();
		int i=top.first;
		int j=top.second;
		
		for(int k=0;k<4;k++){
			int ip= i+dx[k];
			int jp= j+dy[k];
			
//nếu p[ip][jp]=1 - có đường đi trên ma trận, ip,jp đều có tọa độ hợp lệ(nằm trong ma trận)
			if(p[ip][jp] && ip>=0 && ip<=n && jp>=0 && jp<=m){
				p[ip][jp]=0;
				
				//khi đến dc điểm cuối thì trả về kết quả
				if(ip==e.first && jp==e.second)
				return d[i][j]+1;
				
				//đẩy tọa độ đỉnh vào trong hàng đợi và tiếp tục xét
				q.push({ip,jp});
				//tăng số bước di chuyển trên ma trận lên 1 đơn vị
				d[ip][jp]=d[i][j]+1;
			}
		}
	}
	return -1;
}





string np[10001];
void sinhnp(){
	int i=1;
	np[1]='1';
	queue<string> q;
	q.push("1");
	while(i<=10000){
		string pt=q.front();
		q.pop();
		string dau=pt+'0';
		string cuoi=pt+'1';
		q.push(dau);
		q.push(cuoi);
		++i;
		np[i]=dau;
		++i;
		np[i]=cuoi;
	}
	
}


int bailam(int s,int t){
	queue<pair<int,int>> q;
	set<int> se;
	q.push({s,0});
	se.insert(s);
	while(!q.empty()){
		auto dau=q.front();
		q.pop();
		if(dau.first==t) return dau.second;
		if(dau.first*2==t || dau.first-1==t) return dau.second+1; 
		if(se.find(dau.first*2) == se.end() && dau.first<t){
			se.insert(dau.first*2);
			q.push({dau.first*2,dau.second+1});
		}
		if(se.find(dau.first -1) ==se.end() && dau.first >1){
			se.insert(dau.first-1);
			q.push({dau.first-1,dau.second+1});
		}
	}
}


int main(){
	/*
	sinhnp();
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cout << np[i] << ' ';
	}
	*/
	
	/*
	int s,t;
	cin >> s >> t;
	cout << bailam(s,t);
	*/
	
	nhap();
	cout << giai();
	
}