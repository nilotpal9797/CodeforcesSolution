//Given a tree where each node has a value associated with it and q queries each of the form u output the minimum of the subtree
// and maximum of the subtree of u
//n<=10^6 Q<=10^6
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair

vector<int> G[100005];
int vis[100005];
ll wt[100005];
ll minimum[100005];
ll maximum[100005];
ll dp[100005];
int n;
const ll inf=99999999;

ll dfs(int st){
  vis[st]=1;
  if(dp[st]!=inf)return dp[st];
  ll ans=wt[st];
  for(int i=0;i<G[st].size();i++){
     if(vis[G[st][i]]==0){
        ans=min(ans,dfs(G[st][i]));
     }
  }
 return dp[st]=ans;
}

int main(){
  cin >> n;
  fill(dp,dp+n+1,inf);
  ll a,b,c;
  for(int i=1;i<=n;i++)//weight of nodes can be negative
   cin >> wt[i];
  for(int i=0;i<n-1;i++){ // The input tree
     cin >> a >> b;
     G[a].pb(b);
     G[b].pb(a);
  }
 a=dfs(1);
 int q;
 cin >> q;
 while(q--){
  cin >> a;
  cout << dp[a] << endl;
 }
 return 0;
}
