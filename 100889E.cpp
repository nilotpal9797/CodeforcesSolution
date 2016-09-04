#include<bits/stdc++.h>
using namespace std;

int main(){
 int t;
 cin >> t;
 while(t--){
 int n,m;
 int f=0;
 cin >> n >> m;
 int a,b;
 for(int i=0;i<m;i++){
  cin >> a >> b;
  if(a==1 && b==n){f=1;}
 }
 if(f)cout <<"Jorah Mormont\n";
 else cout << "Khal Drogo\n";}
 return 0;
}
