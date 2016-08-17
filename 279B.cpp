#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum[100005];
ll arr[100005];

int main(){
 ll n ,t;
  cin >> n >> t;
  for(int i=0;i<n;i++)
   cin >> arr[i];
  sum[0]=arr[0];
  for(int i=1;i<n;i++)
   sum[i]=sum[i-1]+arr[i];
  ll ans=-10,xx,yy;
  for(int i=0;i<n;i++){
    if(i==0)xx=0;
    else xx=sum[i-1];
    yy=t+xx;
    ll lo=0;ll hi=n-1;
    if(arr[i]>t)lo=i-1;
    else{
    while(lo<hi){
       int mid=(lo+hi+1)/2;
       if(sum[mid]>yy)hi=mid-1;
       else lo=mid;
    }
  }
   ans=max(ans,lo-i+1);
  }
  cout << ans << endl;
  return 0;
}
