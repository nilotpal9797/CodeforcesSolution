//Given a weighted tree i.e wts are associated with every node and q queries each of the form u , output the
//wt of the subtree of the node u.Subtree includes u also
//n < 10^5 Q<=10^6
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
vector<int> G[100005];
ll dp[100005];
int vis[100005];
int wt[100005];

ll dfs(int st){
  vis[st]=1;
  if(dp[st]!=-1)return dp[st];
  ll sum=wt[st];
  for(int i=0;i<G[st].size();i++){
     if(vis[G[st][i]]==0){
        sum+=dfs(G[st][i]);
     }
  }
  return dp[st]=sum;
}


int main(){
 int n,a,b;
 memset(dp,-1,sizeof(dp));
 cin >> n;
 for(int i=1;i<=n;i++)
  cin >> wt[i];
 for(int i=0;i<n-1;i++){
    cin >> a >> b;
    G[a].pb(b);
    G[b].pb(a);
  }
 ll ans=dfs(1);
 int q;
 cin >> q;
 while(q--){
    cin >> a;
    cout << dp[a] << endl;
 }
 return 0;
}
