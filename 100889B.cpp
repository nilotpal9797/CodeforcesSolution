#include<bits/stdc++.h>
using namespace std;

vector<long long> v;

int main(){
 int t;
 cin >> t;
 while(t--){
  long long  n,x;
  v.clear();
  cin >> n;
  for(int i=0;i<n;i++){
     cin >> x;
     v.push_back(x);
   }
  int c=0;
  int p=0,q=n-1;
  while(p<q){
     if(v[p]==v[q]){p++;q--;}
     else{
           long long s1=v[p];
           long long s2=v[q];
           while(p<q && s1!=s2){
                  if(p-q==1 && s1!=s2){c++;p++;q--;break;}
                  if(s1<s2){p++;s1+=v[p];c++;}
                  else if(s1>s2){q--;s2+=v[q];c++;}
           }
           p++;q--;
     
     }
   }
   cout << c << endl;
 }

 return 0;
}

[close]
