//Given a tree find the lowest common ancestor of the given 2 vertices
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

vector<int> G[100005];
int lev[1000006];
int vis[1000006];
int par[1000006];
int dp[100005][17];
int n;

void dfs(int st,int p){
  vis[st]=1;
  lev[st]=lev[p]+1;
  for(int i=0;i<G[st].size();i++)
   if(vis[G[st][i]]==0)
    dfs(G[st][i],st);
 }

void preprocess(){
  for(int i=0;i<=1000004;i++)
   for(int j=0;j<17;j++)
    dp[i][j]=-1;
  for(int i=1;i<=n;i++)
   dp[i][0]=par[i];
   dp[1][0]=-1;
 for(int i=1;(1<<i)<=n;i++ )
  for(int j=1;j<=n;j++)
   if(dp[j][i-1]!=-1)
    dp[j][i]=dp[dp[j][i-1]][i-1];

 }

int lca(int a,int b){
 if(lev[a]< lev[b]){
   int t;
   t=a;a=b;b=t;
  }
 // cout << "level of a and b is "<<lev[a]<<" "<< lev[b]<<endl;
 int l=1;
 for(l=1;1<<l < lev[a];l++);
 l--;
// cout <<"l here is " << l << endl;
 for(int i=l;i>=0;i--)
  if(lev[a]-(1<<i) >= lev[b])
    a=dp[a][i];
// cout << "a here is " << a << endl;
 if(a==b)return a;
 for(int i=l;i>=0;i--)
  if(dp[a][i]!=-1 && dp[a][i]!=dp[b][i]){
    a=dp[a][i];b=dp[b][i];//cout<<"yoyo"<< endl;
  }
 return dp[a][0];
}

int main(){
 //int n;
 cin >> n;
 int x,y;
 memset(vis,0,sizeof(vis));
 for(int i=0;i<n-1;i++){
    cin >> x >> y;
    G[x].pb(y);
    par[y]=x;
  }
 par[1]=0;
 lev[0]=-1;
 dfs(1,0);
 preprocess();
 int q;
 cin >> q;
 while(q--){
   cin >> x >> y;
   int papa=lca(x,y);
   cout << lev[x]+lev[y]-2*lev[papa] <<endl;
  }
 return 0;
}
