//phần tử đầu tiên lớn hơn bên phải
/* 3 4 2 5 1 6 2
	   []
	   4 5 5 6 6 -1 -1
	*/
	
//diện tích hình chữ nhật lớn nhất trên biểu đồ
/* 6 2 5 4 5 1 6
i: 0 1 2 3 4 5 6
  stack []
  
  i=7 -> xét tiếp khi nào hết pt, stack rỗng thì thôi
    area: 6 5 5 12 10 6 7
    max: 12
    
*/

#include <iostream>
#include <stack>
using namespace std;
int main(){
	/*
	int n;
	cin >> n;
	int p[n],q[n];
	stack<int> st;
	for(int &x : p){
		cin >> x;
	}
	for(int i=0;i<n;i++){
	     if(st.empty()){
	     	st.push(i);
		 }else{
		 	while(!st.empty() && p[st.top()] < p[i]){
		 		  q[st.top()]=p[i];
		 		  st.pop();
			 }
			 st.push(i);
		 }
	}
	while(!st.empty()){
		q[st.top()]=-1;
		st.pop();
	}
	for(int x : q){
		cout << x << ' ';
	}
	*/
	
	int n;
	cin >> n;
	int p[n];
	for(int &x : p){
		cin >> x;
	}
	stack<int> st;
	int i=0;
	int m=INT_MIN;
	while(i<n){
		if(st.empty() || p[i]>=p[st.top()]){
			st.push(i);
			++i;
		}else{
			int idx=st.top();
			st.pop();
			if(st.empty()){
				m=max(m,i*p[idx]);
			}else{
				m=max(m,p[idx]*(i-st.top()-1));
			}
		}
	}
	while(!st.empty()){
		int idx=st.top();
			st.pop();
			if(st.empty()){
				m=max(m,i*p[idx]);
			}else{
				m=max(m,p[idx]*(i-st.top()-1));
	        }
        }
        cout << m;
}