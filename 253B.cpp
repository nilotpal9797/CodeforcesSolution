#include<bits/stdc++.h>
using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
  int n;
  cin>>n;
  
  vector<int>arr;
  
  for(int i=0;i<n;++i){
     int x;
     cin>>x;
     arr.push_back(x);
  
  }
  
  sort(arr.begin(),arr.end());
  
  int ans=INT_MAX;
  
  for(int i=0;i<n;++i){
  
     vector<int>::iterator itup;
     
     itup=upper_bound(arr.begin()+i+1,arr.end(),2*arr[i]);
     
     int idx=itup-arr.begin();
     
     ans=min(ans,i+n-idx);
  
  
  }

  cout<<ans<<"\n";
   return 0;
}
