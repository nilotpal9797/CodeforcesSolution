#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
typedef long long ll;

int main(){
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 ll arr[100005];
 ll arr1[100005]={0};
 ll arr2[100005]={0};
 int n;
 cin >> n;
 for(int i=0;i<n;i++)
  cin >> arr[i];
 if(arr[0]>=0)arr1[0]=1;
 for(int i=1;i<n;i++)
  if(arr[i]>=0)arr1[i]=(arr1[i-1]+1);
  else arr1[i]=arr1[i-1];
 if(arr[n-1]<=0)arr2[n-1]=1;
 for(int i=n-2;i>=0;i--)
  if(arr[i]<=0)arr2[i]=1+arr2[i+1];
  else arr2[i]=arr2[i+1];
 ll ans=inf;
 for(int i=0;i<n-1;i++)
  ans=min(ans,arr1[i]+arr2[i+1]);
  cout << ans << endl;
  return 0;
