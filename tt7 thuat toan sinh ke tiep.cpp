//Bài toán sinh xâu nhị phân có độ dài n
//sinh xâu nhị phân có độ dài n thỏa mãn có k bit 1
//* thường dùng trong các bài toán liệt kê

//sinh tập con k phần tử của tập n phần tử
//sinh hoán vị của n phần tử

#include <iostream>
#include <algorithm>
using namespace std;

//tạo mảng p để lưu các xâu nhị phân có độ dài n
int n,p[100],cuoi;//k;
int k;
int cnt;

//bước khởi tạo: cho tất cả các phần tử từ 1 -> n bằng 0
/*
  void khoitao(){
	for(int i=1;i<=n;i++){
		p[i]=0;
	}
  }
*/

//cài đặt thuật toán sinh -> sinh ra các xâu nhị phân có độ dài n
void sinh(){
	//duyệt từ bit (phần tử) cuối cùng
	int i=n;
	//cứ gặp bit là 1 thì cho bit đó bằng 0 -> tiếp tục duyệt
	while(i>=1 && p[i]==1){
		p[i]=0;
		--i;
	}
	//khi gặp bit là 0 thì dừng duyệt và cho bit đó bằng 1
	
	//nếu i chạy qua tất cả các bit rồi thì không xét thêm nữa
	if(i==0)
		cuoi=0; //biến cuoi để kiểm tra xem có phải xâu cuối cùng chưa
	else
	p[i]=1;
}

/*
void ktao_tapcon(){
	for(int i=1;i<=k;i++){
		p[i]=i;
	}
}
*/

//khi p[i] đạt giá trị max là n-k+i thì ngừng duyệt và tiếp tục xét đến các giá trị bên trái
void sinhtapcon(){
	int i=k;//vẫn xét từ phần tử thứ k
	while(i>=1 && p[i]== n - k + i){
		--i;
	}
	if(i==0){
		cuoi=0;
	}
	else{
		p[i]++;
		for(int j=i+1;j<=k;j++){
			p[j]=p[j-1]+1;
		}
	}
}

/*
bool kiemtra(){
    int cnt=0;
    for(int i=1;i<=n;i++){
    	cnt+=p[i];
	}
	return cnt==k;
}
*/
/*
void khoi_tao(){
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
}
*/
void sinh_hoanvi(){
	int i=n-1;
	while(i>=1 && p[i]>p[i+1]){
		--i;
	}
	if(i==0){
		cuoi=0;
	}
	else{
		int j=n;
		while(p[i]>p[j] && j>=i+1){
			--j;
		}
		swap(p[i],p[j]);
		reverse(p+i+1,p+n+1);
	}
}

void ktao(){
	p[1]=n;
	cnt=1;
}

void sinh_phanhoach(){
	int i=cnt;
     while(i>=1 && p[i]==1){
     	--i;
	 }
	 if(i==0){
	 	cuoi=0;
	 }
	 else{
	 	p[i]--;
	 	int dai= cnt-i+1;
	 	cnt=i;
	 	int chia=dai/p[i];
	 	int du=dai%p[i];
        if(chia){
        	for(int j=1;j<=chia;j++){
        		cnt++;
        		p[cnt]=p[i];
			}
		}
		if(du){
			++cnt;
			p[cnt]=du;
		}	 	
	 }
}


int main(){
	cin >> n;// >> k;
	cuoi=1;
//	khoitao();
   // ktao_tapcon();
  // khoi_tao();
  ktao();
   
   
	//in ra các xâu nhị phân 
	/*
	while(cuoi){
		//if(kiemtra()){
		for(int i=1;i<=n;i++){
			cout << p[i];
		 }
		cout << endl;
 	  //}
 	   sinh();
   }
   */
   
   /*
   while(cuoi){
   	for(int i=1;i<=k;i++){
   		 cout << p[i];
	   }
	   cout << endl;
	   sinhtapcon();
   }
   */
   
   /*
   while(cuoi){
   	for(int i=1;i<=n;i++){
   		cout << p[i];
	   }
	   cout << endl;
	   sinh_hoanvi();
   }
   */
   
   while(cuoi){
   	for(int i=1;i<=cnt;i++){
   		cout << p[i] << ' ';
	   }
	   cout << endl;
	   sinh_phanhoach();
   }
}



/* MÃ GIẢ THUẬT TOÁN SINH
      <khởi tạo cấu hình đầu tiên>
      while(<khi chưa phải cấu hình cuối cùng>){
       <in ra cấu hình hiện tại>
       <sinh ra cấu hình tiếp theo>
  */
  
  
  /*
  có thể sử dụng các hàm có sẵn để sinh ra các hoán vị của n phần tử
  +) cần khởi tạo các phần tử trong mảng,vector rồi truyền vào hàm
* next_permutation(p,p+n) -> hàm sẽ trả về true(1) nếu vẫn sinh dc các hoán vị kế tiếp
   trả về false(0) nếu không sinh ra dc hoán vị nào nữa
* prev_permutation(p,p+n) -> ngược lại 
  */
  
