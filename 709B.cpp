//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//
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
 ll n,a;
 vector<ll> v;
 ll x;
 cin >> n >> a;
 for(int i=0;i<n;i++){
  cin >> x;v.pb(x);}
 int f=0;
 int idx=-1;int l=0;int r=n-1;
for(int i=0;i<n;i++)
 if(v[i]==a){f=1;break;}
 if(f==0)v.pb(a);
 sort(v.begin(),v.end()); ll ans=99999999999999;
 for(int i=0;i<v.size();i++)
  if(v[i]==a){idx=i;break;}
  if(f==1){
    if(n==1){ans=0;cout << ans << endl;return 0;}
   if(idx==0){ans=v[n-2]-a;}
   else if(idx==n-1){ans=v[n-1]-v[0];}
   else{
     l=0;r=n-2;
     while(l<=n-2){
      if(idx+r <n && idx-l>=0){
          ans=min(2*(v[idx+r]-a)+a-(v[idx-l]),ans);
      }
       l++;r--;
     }
     l=0;r=n-2;
     while(l<=n-2){
      if(idx+r <n && idx-l>=0){
          ans=min((v[idx+r]-a)+2*(a-(v[idx-l])),ans);
      }
       l++;r--;
    }

   }
   cout << ans << endl;
   return 0;
  }
  if(n==1){cout <<0  << endl;return 0;}
  l=0;r=n-1;
  if(idx==0)ans=v[n-1]-a;
  else if(idx==n){ans=a-v[1];}
  else{
 ///left travel

 while(l<=n-1){
  if(idx+r <=n && idx-l>=0){
      ans=min(2*(v[idx+r]-a)+a-v[idx-l],ans);
  }
   l++;r--;
 }
 l=0;r=n-1;
 while(l<=n-1){
  if(idx+r <=n && idx-l>=0){
      ans=min((v[idx+r]-a)+2*(a-v[idx-l]),ans);
  }
   l++;r--;
  }
 }
cout << ans << endl;
return 0;
}
