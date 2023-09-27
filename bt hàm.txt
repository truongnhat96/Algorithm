#include <iostream>
#include <math.h>
using namespace std;

//xay dung ham kiem tra so nguyen to
 bool checksnt(int a){
    for(int i=2; i<=sqrt(a);i++){
       if (a%i==0)
        {
           return 0;
       }  
    }
    return a>1;
 }

//kiem tra tat ca chu so trong 1 so co la snt ko
bool kiemtra(int n){
    while (n!=0)
    {   int s=n%10;
        n/=10;
        if(s!=2 && s!=3 && s!=5 && s!=7){
        return 0;
        }
    
    }
    return true;
}
//kiem tra tong cua chu so do co phai so nguyen to khong?
bool tong(int n){
  int s=0;
  while (n!=0)
  {   s+=n%10;
  n/=10;

}
if(checksnt(s))
return 1; 
else return 0;
}

 int main(){
     int l,r;
     cin >> l >> r;
    
      int i=0; 
      for(l;l<=r;l++){    
       if(kiemtra(l) && checksnt(l) && tong(l)){
        ++i;
       }
      }    
     cout << i << endl;

// bool nt(int n){
//     for(int i=2;i<=sqrt(n);i++){
//         if(n%i==0){
//           return 0;
//         }
//     }
//     return n>1;
// }



//int main(){
    // int l,r;
    // cin >> l >> r;
    // if(l>0 && r>0){
    //     for(l;l<=r;l++){
    //         if(nt(l)){
    //             cout << l << endl;
    //         }
    //     }
    // }
//     int t;
//     cin >> t;
// while (t--)
// {  int s;
//     cin >> s;
//     if(nt(s)){
//       cout << "YES\n";
//     }else{
//         cout << "NO\n";
//     }
// }


    system("pause");
}