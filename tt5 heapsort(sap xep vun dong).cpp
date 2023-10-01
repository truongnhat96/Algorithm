#include <iostream>
using namespace std;

//DO PHUC TAP O(nlogn)

//xay dung ham minh hoa cay nhi phan hoan chinh
void heapify(int a[],int n,int i){
	int l=2*i+1;  //tao chi so cho not trai
	int r=2*i+2;  //tao chi so cho not phai
	int lagest=i; //tao chi so phan tu lon nhat hien tai
	
	//tien hanh so sanh cac not cha voi not con
	if(l<n && a[l]>a[lagest])
	  lagest=l;
	if(r<n && a[r]>a[lagest])
	  lagest=r;
	  
	//neu chi so lon nhat duoc cap nhat thi tien hanh hoan doi 2 phan tu lon nhat hien tai va pt ban dau
	//sau do tien hanh de quy heapify them 1 lan nua
	  if(lagest!=i){
	  	swap(a[lagest],a[i]);
	  	heapify(a,n,lagest);
	  }
}

void heapsort(int p[],int n){
	//xay dung max heap
	//tao chi so i=n/2-1 la chi so den phan tu cua not goc can xet
	for(int i=n/2-1;i>=0;i--){
		heapify(p,n,i);
	}
	
	//tien hanh thuat toan heapsort
	//chi xet phan tu dau cua mang, va tien hanh hoan doi voi cac phan tu cuoi cung cua mang hien tai
	for(int i=n-1;i>=0;i--){
		swap(p[i],p[0]);
		
		//sau do tien hanh heapify de dua ve max heap 1 lan nua
		heapify(p,i,0);
	}
}
int main(){
	int n;
	cin >> n;
	int p[n];
	for(int i=0;i<n;i++){
		cin >> p[i];
	}
	heapsort(p,n);
	for(int i=0;i<n;i++){
		cout << p[i] << " ";
	}
}
