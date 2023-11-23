#include <iostream>
using namespace std;

//ĐỘ PHỨC TẠP O(nlogn)

//tư tưởng: chia để trị

//Xây dựng hàm phân hoạch lomuto
int part(int a[],int l,int r){
	
	//lưu phần tử cuối cùng của mảng (là chốt) để so sánh
	int pivot=a[r];
	
	//tạo chỉ số i là chỉ số đứng trước phần tử đầu tiên của mảng
	int i=l-1;
	
	//duyệt mảng đến phần tử thứ r-1 (ko duyệt pt pivot)
	for(int j=0;j<r;j++){
		if(pivot>=a[j]){
			++i;
			swap(a[i],a[j]);
		}
	}
	//đưa phần tử pivot về giữa mảng
	++i;
	swap(a[i],a[r]);
	
	//trả về vị trí thứ i -> chính là vị trí của pt pivot
	return i;
}

//xây dựng thuật toán quick sort sử dụng đệ quy
void quicksort(int a[],int l,int r){
	if(l>=r)
	return;
    int p=part(a,l,r);
    //p là phần tử pivot sau khi phân hoạch
    //không xét đến phần tử pivot sau khi phân hoạch
    
    quicksort(a,l,p-1); //de quy phan ben trai cua pt pivot
    quicksort(a,p+1,r); //de quy phan ben phai cua pt pivot
}


//xây dựng hàm PHÂN HOẠCH HOARE
int part2(int a[],int l,int r){
	
	//cho phần tử chôt bằng phần tử đầu tiên của mảng 
	int pivot= a[l];
	
	//tạo biến i là chỉ số đứng trước chỉ số đầu tiên của mảng 
	//tạo biến j là chỉ số đứng sau chỉ số cuối cùng của mảng
	int i=l-1;
	int j=r+1;
	
	//sử dụng vòng lặp do while
	//dùng vòng lặp vô tận, xét các cặp NGHỊCH THẾ của mảng.
	/*điều kiện để 2 phần tử là nghịch thế:
	  phần tử thuộc bên trái- a[i] >= pivot(phần tử chốt) 
	  phần tử thuộc bên phải- a[j] <= pivot(phần tử chốt)
	                    */
	//nếu chưa thỏa mãn đk là nghịch thế thì tăng i lên,giảm j xuống để kiểm tra tiếp                   
	while(true){
		do{
			++i;
		}while(a[i]<pivot);
		do{
			--j;
		}while(a[j]>pivot);
		if(i<j)
		
		//khi thỏa mãn 2 phần tử là nghịch thế thì tiến hành đổi vị trí cho nhau
		swap(a[i],a[j]);
		else  //khi i>j tức là đã duyệt hết các phần tử của mảng thì sẽ trả về chỉ số j ->chỉ số phần tử thuộc bên phải   
		return j;
	}
}

void quicksort1(int a[],int l,int r){
	if(l>=r)
	return;
	int p=part2(a,l,r);
	
	//sử dụng đệ quy, lấy toàn bộ các phần tử thuộc vế trái tính cả p
	quicksort1(a,l,p);
	
	//lấy toàn bộ các phần tử thuộc vế phải tính từ p+1
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
