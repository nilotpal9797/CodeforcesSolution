#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

vector<ll> v;
ll n;

int main(){
 cin >> n;
 ll x;
 for(int i=0;i<n;i++){
    cin >> x;
    v.pb(x);
 }
 sort(v.begin(),v.end());
 int t=0,c=0;
 t=v[0];
 for(int i=1;i<n;i++){
    if(t>v[i])c++;
    else t+=v[i];
 }
 cout << n-c << endl;
 return 0;
}
