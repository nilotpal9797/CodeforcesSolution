//Gievn a weighted tree and Q queries each of the type v answer the distance of the given node i.e v from the root i.e 1
// n<10^5 Q<10^6 
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

int dp[100035];
int vis[100035];
vector<pair<int,int> > G[100035];

void dfs(int s,int p,int d){
  dp[s]=dp[p]+d;
  vis[s]=1;
  for(int i=0;i<G[s].size();i++){
     if(vis[G[s][i].second]==0){
        dfs(G[s][i].second,s,G[s][i].first);
     }
  }
}


int main(){
 int n,m,a,x,y;
 cin >> n;
 for(int i=0;i<n-1;i++){
    cin >> x >> y >> a;
    G[x].pb(mp(a,y));
    G[y].pb(mp(a,x));
 }
 dp[0]=0;
 dp[1]=0;
 dfs(1,0,0);
 int q;
 cin >> q;
 while(q--){
    cin >> x;
    cout << dp[x] << endl;
 }
  return 0;
}
