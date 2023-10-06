#include <iostream>
using namespace std;

//DO PHUC TAP O(nlogn)

//xay dung ham phan hoach lomuto
int part(int a[],int l,int r){
	
	//luu phan tu cuoi cung cua mang (la chot) de so sanh
	int pivot=a[r];
	
	//tao chi so i la chi so dung truoc chi so dau tien cua mang
	int i=l-1;
	
	//duyet mang den phan tu thu r-1 (ko duyet pt pivot)
	for(int j=0;j<r;j++){
		if(pivot>=a[j]){
			++i;
			swap(a[i],a[j]);
		}
	}
	//dua phan tu pivot ve giua mang
	++i;
	swap(a[i],a[r]);
	
	//tra ve vi tri thu i -> chinh la vi tri cua phan tu pivot
	return i;
}

//xay dung thuat toan quick sort su dung de quy
void quicksort(int a[],int l,int r){
	if(l>=r)
	return;
    int p=part(a,l,r);
    //p la phan tu pivot sau khi phan hoach
    //khong xet den phan tu pivot sau khi phan hoach
    
    quicksort(a,l,p-1); //de quy phan ben trai cua pt pivot
    quicksort(a,p+1,r); //de quy phan ben phai cua pt pivot
}


//xay dung ham phan hoach hoare
int part2(int a[],int l,int r){
	
	//cho phan tu chot = phan tu dau tien cua mang
	int pivot= a[l];
	
	//tao bien i la chi so dung truoc chi so dau tien cua mang
	//tao bien j la chi so dung sau chi so cuoi cung cua mang
	int i=l-1;
	int j=r+1;
	
	//dung vong lap vo tan, xet cac cap nghich the cua mang.
	/*dieu kien de 2 phan tu la nghich the:
	  phan tu thuoc ben trai- a[i] >= pivot(phan tu chot) 
	  phan tu thuoc ben phai- a[j] <= pivot(phan tu chot)
	                    */
	//neu chua thoa man dk la nghich the thi tang i len,giam j xuong de kiem tra tiep                   
	while(true){
		do{
			++i;
		}while(a[i]<pivot);
		do{
			--j;
		}while(a[j]>pivot);
		if(i<j)
		
		//khi thoa man la 2 phan tu nghich the thi tien hanh doi vi tri cho nhau
		swap(a[i],a[j]);
		else  //khi i>j tuc la da duyet het cac phan tu cua mang thi se tra ve chi so j  
		return j;
	}
}

void quicksort1(int a[],int l,int r){
	if(l>=r)
	return;
	int p=part2(a,l,r);
	
	//su dung de quy, lay toan bo cac phan tu thuoc ve trai tinh ca p
	quicksort1(a,l,p);
	
	//lay toan bo cac phan tu thuoc ve phai tinh tu p+1
	quicksort1(a,p+1,r);
}


int main(){
	int n;
	cin >> n;
	int p[n];
	for(int i=0;i<n;i++){
		cin >> p[i];
	}
	quicksort1(p,0,n-1);
	for(int i=0;i<n;i++){
		cout << p[i] << " ";
	}
}
