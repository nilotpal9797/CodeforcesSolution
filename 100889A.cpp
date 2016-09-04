#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
 int t;
 cin >> t;
 while(t--){
  int n,x;
  cin >> n;
  v.clear();
  for(int i=0;i<n;i++){
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  long long ans=0;
  for(int i=0;i<(n/2);i++)
   ans+=(v[n-i-1]-v[i]);
   cout << ans << endl;
 }

 return 0;
}
