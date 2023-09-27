#include <iostream>
#include <string>
using namespace std;

struct qlsv{
	string ten;
	double diem;
};

qlsv nhap(qlsv &x){
	cin.ignore();
	getline(cin,x.ten);
	cin >> x.diem;
	return x;
}
void in(qlsv t){
	cout << t.ten << " " << t.diem << endl;
}
int main(){
	int n;
	cin >> n;
	qlsv a[n];
	for(int i=0;i<n;i++)
	nhap(a[i]);
	  for(int i=0;i<n;i++)
	  in(a[i]);
}
