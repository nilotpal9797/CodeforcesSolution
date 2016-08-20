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

ll t[100005];
ll th[100005];

int main(){
 int n;
 ll x,y,z;
 cin >> n;
 ll arr[100005];
 for(int i=0;i<n;i++)
   cin >> arr[i];
 for(int i=0;i<n;i++){
   x=0;y=0;z=arr[i];
   while(z%2==0){
      x++;z/=2;
   }
   while(z%3==0){
      y++;z/=3;
   }
  t[i]=x;th[i]=y;
 }
 ll max2=-1,max3=-1;
 for(int i=0;i<n;i++){
     max2=max(max2,t[i]);
     max3=max(max3,th[i]);
 }
 for(int i=0;i<n;i++){
     arr[i]=arr[i]*pow(2,max2-t[i]);
     arr[i]=arr[i]*pow(3,max3-th[i]);
 }
 ll f=1;
 ll ans=arr[0];
 for(int i=1;i<n;i++){
    if(arr[i]!=ans){f=0;break;}
 }
 if(!f)cout << "No\n";
 else cout << "Yes\n";
 return 0;
}
