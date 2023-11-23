//tìm chu trình euler dựa trên danh sách kề của đồ thị vô hướng
#include <bits/stdc++.h>
using namespace std;
      int n,m;
      set<int> s[1001]; //sử dụng mảng các set để lưu danh sách kề
      
      int level[1001];
      
      //nhập vào danh sách cạnh
	  //thực hiện chuyển sang danh sách kề 
      void input(){
      	 cin >> n >> m;
      	 for(int i=0;i<m;i++){
      	 	  int x,y;
      	 	  cin >> x >> y;
      	 	  s[x].insert(y); //với đồ thị có hướng chỉ cần lưu danh sách của x
      	 	  s[y].insert(x);
      	 	  
      	 	  //tìm bậc của các đỉnh trong đồ thị
      	 	  level[x]++;
      	 	  level[y]++;
		   }
	  }
	  
	  //xây dựng thuật toán tìm chu trình euler
	  void euler(int n){
	  	
	  	//tạo cấu trúc dữ liệu ngăn xếp để duyệt các đỉnh
	  	stack<int> st;
	  	
	  	//tạo vector để lưu các đỉnh là chu trình euler
	  	vector<int> v;
	  	
	  	//đưa đỉnh vào ngăn xếp
	  	st.push(n);
	  	
	  	//tiến hành lặp khi ngăn xếp chưa rỗng
	  	while(!st.empty()){
	  		
	  		//lấy ra đỉnh đầu của ngăn xếp
	  		int d=st.top();
	  		
	  		//kiểm tra nếu danh sách kề của đỉnh đầu khác 0
	  		if(s[d].size()!=0){
	  			//đưa các đỉnh kề của đỉnh đầu vào ngăn xếp và xóa đỉnh đó đi
	  			int o = *s[d].begin();
	  			st.push(o);
	  			s[d].erase(o);
	  			s[o].erase(d);
			  }else{
			  	
//nếu danh sách kề của đỉnh đó =0 thì xóa đỉnh đó khỏi ngăn xếp và đưa vào chu trình euler
			  	st.pop();
			  	v.push_back(d);
			  }
		  }
		  for(int t : v){
		  	cout << t << " ";
		  }
	  }
int main(){
	input();
	//kiểm tra nếu là đường đi euler thì phải xuất phát từ đỉnh bậc lẻ thứ 1 hoặc thứ 2
	euler(6);
}