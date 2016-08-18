#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair

vector<ll> v1,v2;

int main(){
 int n,m;ll x;
 cin >> n;
 for(int i=0;i<n;i++){
    cin >> x;
    v1.pb(x);
 }
 sort(v1.begin(),v1.end());
 cin >> m;
 for(int i=0;i<m;i++){
    cin >> x;
    v2.pb(x);
 }
 ll xx,yy,aa,bb;
 ll d,ans=-20000000;
 int idx;
 sort(v2.begin(),v2.end());
 vector<ll>::iterator it=v2.begin();
 for(int i=0;i<n;i++){
    d=v1[i];
    it=lower_bound(v2.begin(),v2.end(),d);
    idx=it-v2.begin();
    xx=(3*(n-i))+(2*i);
    yy=(3*(m-idx))+2*idx;
    if(xx-yy>ans){ans=xx-yy;aa=xx;bb=yy;}
    else if((xx-yy==ans)&& xx>aa ){aa=xx;bb=yy;}
 }
  if(2*(n-m)>ans){aa=2*n;bb=2*m;}
  cout << aa<<":"<<bb<< endl;
  return 0;
}
