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
vector<int > G[30005];
int vis[30005];
int lev[300005];
 void bfs(int st){
   queue<int> Q;
   Q.push(st);
   lev[st]=0;
   vis[st]=1;
   while(!Q.empty()){
     int a=Q.front();
     Q.pop();
     for(int i=0;i<G[a].size();i++){
       if(vis[G[a][i]]==0){
         Q.push(G[a][i]);
         vis[G[a][i]]=1;
         lev[G[a][i]]=lev[a]+1;
       }
     }
   }
 }

 int main(){
  int n,k;
  MEM(lev,-1);
  MEM(vis,0);
  sc2i(n,k);
  int x;
  for(int i=1;i<n;i++){
    scanf("%d",&x);
    G[i].pb(i+x);
  }
 bfs(1);
 if(lev[k]==-1)cout<<"NO\n";
 else cout<<"YES\n";
 return 0;
 }
