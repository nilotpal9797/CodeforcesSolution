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
vector<int> G[100005];
int cat[100005]={0};
ll ans=0;int n,m,x,y;
int vis[100005]={0};

void dfs(int s,int c,int p){
  vis[s]=1;if(cat[s]==1)c++;else c=0;
  if(c>m)return;
  if(G[s].size()==1 && G[s][0]==p){ans++;return;}
  for(int i=0;i<G[s].size();i++){
    if(vis[G[s][i]]==0){
       dfs(G[s][i],c,s);
    }
  }
}

int main(){
 cin >> n >> m;
 for(int i=1;i<=n;i++)
    cin >> cat[i];
 for(int i=0;i<n-1;i++){
     cin >> x >> y;
     G[x].pb(y);
     G[y].pb(x);
  }
   dfs(1,0,-1);
  cout << ans << endl;
}
