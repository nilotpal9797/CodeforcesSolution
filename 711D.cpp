//Problem link:- http://www.codeforces.com/problemset/problem/711/D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#define pb push_back
vector<int> G[200005];
int vis[200005]={0};
int mark[200005]={0};
int arr[200005];
vector<int> cycle;

void dfs(int st){
 vis[st]=1;
 for(int i=0;i<G[st].size();i++){
   if(mark[G[st][i]]==1){mark[st]=1;return;}
   else if(vis[G[st][i]]==1){mark[st]=1;cycle.pb(G[st][i]);return;}
   else dfs(G[st][i]);

 }
 mark[st]=1;

}

ll exp(ll a,ll b){
  if(b==0)return 1;
  else if(b==1)return a%M;
  else {
	 ll x=exp(a,b/2)%M;
         x=(x*x)%M;
         if(b&1)x=(x*a)%M;
         return x%M;
     }

 }

int main(){
 int n;
 cin >> n; 
 for(int i=1;i<=n;i++){
   cin >> arr[i];
   G[i].pb(arr[i]);
 }
 for(int i=1;i<=n;i++){
   if(!vis[i]){
     dfs(i);
   }
 }
 ll s=0;
 vector<int> qry;
 for(int i=0;i<cycle.size();i++){
   int x=cycle[i];
   int c=0;
   int p=arr[x];
   while(p!=x){
        c++;
        p=arr[p];
     }
   c++; 
   s+=c;
   qry.pb(c);
 }
 ll ans1=1;
 for(int i=0;i<qry.size();i++)
  ans1 = (ans1 * (exp(2,qry[i])-2))%M; 
  ans1 = (ans1 *(exp(2,n-s)%M))%M;
  cout << ans1 << endl;
  return 0;
 }
