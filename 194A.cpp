#include<bits/stdc++.h>
using namespace std;

int main(){
 int n,k;
 cin >> n >> k;
 int q=(k/n);
 if(q>=3)cout<<0<<endl;
 else if(q==1)cout<<(k%n)<<endl;
 else cout << (n-(k%n))<<endl;
 return 0;
}


