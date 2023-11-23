#include <bits/stdc++.h>
using namespace std;
int m,n;
  vector<int> v[1001]; //tạo mảng vector lưu danh sách kề
  bool tham[1001];
  
  //input đề bài là danh sách kề
  //tiến hành nhập vào và chuyển đổi từ danh sách cạnh sang danh sách kề
  void input(){
  	 cin >> n >> m;
  	 for(int i=0;i<m;i++){
  	 	int x,y;
  	 	cin >> x >> y;
  	 	
  	 	//lưu ý: với đồ thị có hướng chỉ cần đưa đỉnh y vào danh sách kề của đỉnh x
  	 	v[x].push_back(y);
  	 	v[y].push_back(x); 
	   }
	   memset(tham,false,sizeof(tham));
  }
  
  // (*) xây dựng thuật toán tìm kiếm theo chiều rộng BFS
  void bfs(int x){
  	
  	//sử dụng cấu trúc dữ liệu hàng đợi
  	queue<int> q;
  	
  	//đưa đỉnh x vào hàng đợi
  	q.push(x);
  	
  	//đánh dấu đã thăm đỉnh x
  	tham[x]=true;
  	
  	//tiến hành lặp khi hàng đợi chưa rỗng
  	while(!q.empty()){
  		
  		//lấy ra đỉnh ở đầu hàng đợi
  		int g=q.front();
  		
  		//xóa đỉnh đầu trong hàng đợi
  		q.pop();
  		
  		//thăm đỉnh đầu
  		cout << g << " ";
  		
  		//duyệt danh sách kề của đỉnh g
  		for(int z : v[g]){
  			
//nếu đỉnh đó chưa dc duyệt thì tiến hành đưa đỉnh đó vào hàng đợi và đánh dấu là đã duyệt
  			if(!tham[z]){
  				q.push(z);
  				tham[z]=true;
			  }
		  }
	  }
  }
int main(){
      input();
      int p;
      cout << "nhap dinh bat dau duyet tren do thi: ";
      cin >> p;
      bfs(p);
}