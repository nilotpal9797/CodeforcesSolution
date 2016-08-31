//Problem link:- https://www.hackerrank.com/challenges/mandragora
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000005];
int main(){
 int t;
 scanf("%d",&t);
 while(t--){
  int n;
     ll sum=0;
  //memset(sum,0,sizeof(sum));
  scanf("%d",&n);
  for(int i=0;i<n;i++)
   scanf("%lld",&arr[i]);
   sort(arr,arr+n);
  ll ans=-1;
  for(int i=n-1;i>=0;i--){
    sum+=arr[i];
    ans=max(ans,(i+1)*sum);
  }
   printf("%lld\n",ans);
 }
 return 0;
}
