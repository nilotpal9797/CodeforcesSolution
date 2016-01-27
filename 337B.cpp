#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main()
{
  vector<int> v;
  ll arr[200005];
  ll n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>arr[i];
  ll min=arr[0];int index=0;
  for(int i=1;i<n;i++)
    if(arr[i]<=min)
    {
      min=arr[i];
      index=i;
    }
  for(int i=0;i<n;i++)
    if(arr[i]==min)
      v.pb(i);
  ll ans;
  ans=min*n;
  if(v.size()==1){
  ans+=(n-1);
  cout<<ans<<endl;}
  else
  {
    ll maxi=v[1]-v[0];
    for(int i=2;i<v.size();i++)
      if(v[i]-v[i-1]>maxi)
	maxi=v[i]-v[i-1];
        maxi--;
	maxi=max(maxi,(v[0]+(n-1-v[v.size()-1])));
       ans+=maxi;
       cout<<ans<<endl;
  }

//  if(i2!=index)
   // ans+=i2;
 // cout<<ans<<endl;
  return 0;
 }
