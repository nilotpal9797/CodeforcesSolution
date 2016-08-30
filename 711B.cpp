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
 int n;
 cin >> n;
 ll arr[502][502];
 ll row[501]={0};
 ll col[501]={0};
 int r,c;
 for(int i=0;i<n;i++)
  for(int j=0;j<n;j++){
   cin >> arr[i][j];
   if(arr[i][j]==0){r=i;c=j;}
 }
 if(n==1){
    if(arr[0][0]==0){
       cout << 1 << endl;
       return 0;
    }
 }
 ll x;
 for(int i=0;i<n;i++){
   x=0;
  for(int j=0;j<n;j++){
     x+=arr[i][j];
   }
  row[i]=x;
 }
 for(int i=0;i<n;i++){
   x=0;
  for(int j=0;j<n;j++){
     x+=arr[j][i];
   }
  col[i]=x;
 }
 ll d1=0,d2=0;
 ll req;
 if(r!=0)req=row[0];
 else req=row[1];
 int f=1;
 for(int i=0;i<n;i++){
   if(i!=r){
      if(row[i]!=req){
         f=0;break;
      }
  }
 }
if(f==0){cout << -1 << endl;return 0;}
for(int i=0;i<n;i++){
  if(i!=c){
     if(col[i]!=req){
        f=0;break;
     }
 }
}
if(f==0){cout << -1 << endl;return 0;}
else{
      ll pp=req-row[r];
      ll qq=req-col[c];
      if(pp <=0 || qq<=0){cout << -1 << endl;return 0;}
      if(pp!=qq){cout << -1 << endl;return 0;}
      arr[r][c]=pp;
      for(int i=0;i<n;i++){
        x=0;
         for(int j=0;j<n;j++){
            x+=arr[i][j];
         }
        if(x!=req){f=0;break;}
      }
      for(int i=0;i<n;i++){
        x=0;
         for(int j=0;j<n;j++){
            x+=arr[j][i];
         }
        if(x!=req){f=0;break;}
      }
      for(int i=0;i<n;i++){
       d1+=arr[i][i];
      }
      int t1=0,t2=n-1;
      for(;t1<n;t1++){
         d2+=arr[t1][n-1-t1];
      }
    if(f==0){cout << -1 << endl;return 0;}
    if(d1!=req || d2!=req){cout << -1 << endl;return 0;}
    if(d1!=d2){cout << -1 << endl;return 0;}
    else cout << pp << endl;
}
  return 0;
}
