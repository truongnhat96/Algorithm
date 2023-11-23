#include <iostream>
#include <vector>
using namespace std;
int n,m;

//tạo hàm đánh dấu các đỉnh đã đi qua
  bool a[1001];
   vector<int> v[1001];
   
   //input đề bài là danh sách cạnh
   //nhập giá trị và chuyển đổi sang dạng danh sách kề
  void input(){
  	//nhập vào số đỉnh và số cạnh
  	cin >> n >> m;
  	
  	//duyệt và đưa đỉnh đầu và đỉnh cuối vào danh sách kề -> mảng vector
  	for(int i=0;i<m;i++){
  		int x,y;
  		cin >> x >> y;
  		v[x].push_back(y);
  		//với đồ thị có hướng chỉ cần lưu các đỉnh kề với x
  		v[y].push_back(x);
	  }
	  //cho toàn bộ bằng false
	  memset(a,false,sizeof(a));
  }
  
  //xây dựng thuật toán tìm kiếm theo chiều sâu với đệ quy
  void dfs(int t){
  	cout << t << " ";
  	//đánh dấu đã đi qua đỉnh t
  	a[t]=true;
  	
  	for(int x : v[t]){
  		//nếu chưa đi qua đỉnh t thì gọi đệ quy để tiếp tục đi qua các đỉnh còn lại
  		if(!a[x]){
  		  dfs(x);
		  }
	  }
  }


int main(){
	input();
	int p;
	cout << "chon dinh xuat phat tren do thi: ";
	cin >> p;
	dfs(p);
}