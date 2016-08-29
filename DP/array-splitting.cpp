//Problem link:- https://www.hackerrank.com/challenges/array-splitting/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int s,int e,ll arr[],ll sum[]){
  if(s>=e)return 0;
  ll x=sum[e]-(s>0?sum[s-1]:0);
  int f=0;ll xx=0;ll idx;
  for(int i=s;i<=e;i++){
    xx+=arr[i];
    if(2*xx==x){idx=i;f=1;break;}
  }
 if(f==0)return 0;
 else return 1+max(solve(s,idx,arr,sum),solve(idx+1,e,arr,sum));
}


int main(){
 int t;
 cin >> t;
 while(t--){
  ll n;
  ll arr[35000];
  ll sum[35000];
  cin >> n;
  for(int i=0;i<n;i++)
   cin >> arr[i];
   sum[0]=arr[0];
   for(int i=1;i<n;i++)
    sum[i]=arr[i]+sum[i-1];
  ll ans=solve(0,n-1,arr,sum);
  cout << ans << endl;
 }
  return 0;
}
