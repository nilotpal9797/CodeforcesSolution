#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
#include <climits>
#include <list>
using namespace std;

#define sci(x) scanf("%d",&x)
#define scli(x) scanf("%lld",&x)
#define sc2i(x,y) scanf("%d%d",&x,&y)
#define sc2li(x,y) scanf("%lld%lld",&x,&y)
#define pb push_back
#define X first
#define Y second
#define boost cin.tie(0);cout.tie(0)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define pf printf
#define MEM(a,val) memset(a,val,sizeof(a))
#define pi 3.14159265359
#define mp make_pair
#define all(c) c.begin(),c.end() //eg sort(all(v));

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef vector<int> vi;

int main(){
 int n,k;
 ll sum=0,dia=0,ans=0;
 cin >> n >> k;
 map<int,int> M;
 vector<ll> v;
 ll b[100006];
 for(int i=1;i<=n;i++){
   cin >> b[i];
   sum+=b[i];
}
  ll x;
  for(int i=0;i<k;i++){
    cin >> x;
    M[x]=1;
    v.pb(x);
  }
  
 for(int i=1;i<=n;i++){
   if(i==n)
     ans+=b[i]*b[1];
   else 
    ans+=b[i]*b[i+1];
 }
 int p,nx;ll tmp;
 if(n==3){cout<<ans<<endl;return 0;}
 for(int i=0;i<v.size();i++){
   if(v[i]==n){p=n-1;nx=1;}
   else if(v[i]==1){p=n;nx=2;}
   else{p=v[i]-1;nx=v[i]+1;}
   tmp=dia;
   if(M[p]==1)tmp-=b[p];
    ans+=(b[v[i]]*(sum-b[v[i]]-b[p]-b[nx]-tmp));
    dia+=b[v[i]];
 }
 cout << ans << endl;
 return 0;
}
