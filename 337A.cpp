#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  ll n;
  cin>>n;
  int rem=(n%2);
  if(rem!=0)
    cout<<'0'<<endl;
  else
  {
    ll x=n/2;
    if(x%2)
      cout<<x/2<<endl;
    else
      cout<<(x/2 -1)<<endl;
  }
return 0;
}
