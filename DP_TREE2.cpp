//Given a weighted tree with n nodes and Q queries each of the form u,v ,you have to answer
//the wt of the unique path from u to v;
// n <= 10^5 Q<=10^6
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int dp[100005][17];
int vis[100005];
int par[100005];
int dis[100005];
int lev[100005];
vector<pii> G[100005];
int n;

void dfs(int s,int p,int d){
  vis[s]=1;
  lev[s]=lev[p]+1;
  dis[s]=dis[p]+d;
  for(int i=0;i<G[s].size();i++){
      if(vis[G[s][i].Y]==0){
          dfs(G[s][i].Y,s,G[s][i].X);
      }
  }
}
void preprocess(){
   for(int i=0;i<=n;i++)
    for(int j=0;j<17;j++)
     dp[i][j]=-1;
   for(int i=2;i<=n;i++)
    dp[i][0]=par[i];
  for(int i=1;(1<<i )< n;i++)
   for(int j=1;j<=n;j++)
    if(dp[j][i-1]!=-1)
     dp[j][i]=dp[dp[j][i-1]][i-1];
}
int lca(int u,int v){
  if(lev[u]<lev[v]){int t=u;u=v;v=t;}
  int l=1;
  for(l=1;1<<l < lev[u];l++);
  l--;
  for(int i=l;i>=0;i--)
     if(lev[u]-(1<<i) >= lev[v])
       u=dp[u][i];
  if(u==v)return u;
  for(int i=l;i>=0;i--)
    if(dp[u][i]!=-1 && dp[u][i]!=dp[v][i]){
       u=dp[u][i];v=dp[v][i];
    }
  return dp[u][0];
}

int main(){
 int a,b,c;
 cin >> n;
 for(int i=0;i<n-1;i++){
    cin >> a >> b >> c;
    par[b]=a;
    G[a].pb(mp(c,b));
    G[b].pb(mp(c,a));
 }
 lev[0]=-1;
 dis[0]=0;
 dfs(1,0,0);
 preprocess();
 int q;
 cin >> q;
 while(q--){
    cin >> a >> b;
    cout << dis[a]+dis[b]-2*dis[lca(a,b)]<<endl;
 }
 return 0;
}
