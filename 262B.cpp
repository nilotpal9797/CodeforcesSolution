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
vector<ll> ans;
ll nil(ll a ,ll e){
  if(e==1)return a;
  ll x=nil(a,e/2);
  x=x*x;
  if(e%2) return x*a;
  return x;
}

ll fun(ll x){
  ll s=0;
  while(x>0){
    s+=x%10;
    x/=10;
  }
  return s;
}

int main(){
 ll a,b,c;
 cin >> a >> b >> c;
 for(int i=1;i<=81;i++){
   ll x=b*nil(i,a)+c;
   if(x<1000000000 && fun(x)==i)
    ans.pb(x);
 }
 sort(ans.begin(),ans.end());
 cout << ans.size()<<endl;
 for(int i=0;i<ans.size();i++)
  cout << ans[i]<<" ";
  cout << endl;
 return 0;
}
