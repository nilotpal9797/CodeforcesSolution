http://codeforces.com/problemset/problem/20/C
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

vector<pii> G[100005];
ll dis[100005];
int vis[100005];
int par[100005];

void dijkstra(int st){
  priority_queue<pii,vector<pii>,greater<pii> > Q;
  dis[st]=0;
  par[st]=0;
  vis[st]=1;
  int x,y;
  Q.push(mp(0,st));
  while(!Q.empty()){
    int a=Q.top().X;//cost
    int b=Q.top().Y;//node
    vis[b]=1;
    Q.pop();
    for(int i=0;i<G[b].size();i++){
       x=G[b][i].Y;//node
       y=G[b][i].X;//cost
       if(vis[x]==0){
          if(dis[x]> dis[b]+y){
             dis[x]=dis[b]+y;
             par[x]=b;
             Q.push(mp(dis[x],x));
          }
       }
    }
  }
}

int main(){
 int n,m;
 cin >> n >> m;
 fill(dis,dis+100003,987654329919);
 MEM(vis,0);
 int a,b,c;
 for(int i=0;i<m;i++){
   cin >> a >> b >> c;
   G[a].pb(mp(c,b));
   G[b].pb(mp(c,a));
 }
 dijkstra(1);
 int p=n;
 vector<int > papa;
 while(p!=0){
   papa.pb(p);
   p=par[p];
 }
 if(dis[n]==987654329919){
    cout << "-1\n";return 0;
 }
 for(int i=papa.size()-1;i>=0;i--)
  cout << papa[i]<<" ";
 return 0;
}
