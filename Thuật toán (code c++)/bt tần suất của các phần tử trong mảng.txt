// tìm số xuất hiện nhiều nhất trong mảng
// cách thông thường 
#include <bits/stdc++.h>
using namespace std;
int a[101]={0};
int main(){
    int n;
    cin >> n;
    int p[n];
   int max=0;
   for(int i=0;i<n;i++){
      cin >> p[i];
      a[p[i]]++;
   }
   for(int i=0;i<n;i++){
        if(a[p[i]]>max){
         max=a[p[i]];
        }
   }
   for(int i=0;i<n;i++){
      if(a[p[i]]==max){
         cout << p[i] << " ";
         a[p[i]]=0;
      }
   }
   system("pause");
}

// sử dụng map
#include <iostream>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<int,int> m;
    for(int i=0;i<n;i++){
    	int x;
    	cin >> x;
    	m[x]++;
	}
	int max=0;
	for(auto it : m){
		if(it.second > max)
		max=it.second;
	}
	for(auto it : m){
		if(it.second==max)
		cout << it.first << " ";
	}
   system("pause");
}