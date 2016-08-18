#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
vector<ll>  v;

int main(){
 ll x;
 for(int i=1;i<=100000;i++){
   x=i;
   x=(x*(x+1))/2;
   v.pb(x);
 }
 int f=0;
 ll n;
 vector<ll>::iterator it=v.begin();
 cin >> n;
 for(int i=0;i<v.size();i++){
   x=v[i];
   it=lower_bound(v.begin(),v.end(),n-x);
   if(it==v.end())continue;
   if(*it==n-x){f=1;break;}
 }
 if(f)cout << "YES\n";
 else cout << "NO\n";
 return 0;
}
