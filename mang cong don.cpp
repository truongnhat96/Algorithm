//tính tổng các phần tử trong đoạn từ left tới right

#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int p[n+1];
	for(int i=1;i<=n;i++){
		cin >> p[i];
	}
	//sử dụng mảng cộng dồn
	int prefix[n+1]={0};
	for(int i=1;i<=n;i++){
		prefix[i]=prefix[i-1]+p[i];
	}
	
	//tạo truy vấn
	int t;
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		cout << prefix(r)-prefix[l-1] << endl;
	}
}