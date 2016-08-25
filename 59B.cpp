#include<bits/stdc++.h>
using namespace std;

int main(){
 int n,sum=0;
 int arr[105];
 cin >> n ;
 for(int i=0;i<n;i++){
   cin >> arr[i];
   sum+=arr[i];
  }
 if(sum%2)cout<<sum<<endl;
 else{
       int f=0;
       int mini=INT_MAX;
       for(int i=0;i<n;i++)
        if(arr[i]%2){
          f=1;
         mini=min(mini,arr[i]);}
    if(f)cout << sum-mini<<endl;
    else cout << 0 <<endl;
 }
  return 0;
}
