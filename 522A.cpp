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
ll ans=-1;
int vis[500]={0};
vector<int> G[405];

void dfs(int s,ll l){
  vis[s]=1;l++;ans=max(ans,l);
  for(int i=0;i<G[s].size();i++){
    if(vis[G[s][i]]==0){
      dfs(G[s][i],l);
    }
  }
}
map<string,int> M;
 int main(){
 int n,c=0,l1,l3,x,y;
 string s1,s2,s3;
 cin >> n;
 while(n--){
   cin >> s1 >> s2 >> s3;
   l1=s1.length();l3=s3.length();
   for(int i=0;i<l1;i++){
      if(s1[i]>=97 && s1[i]<=122)s1[i]-=32;
   }
   for(int i=0;i<l3;i++){
      if(s3[i]>=97 && s3[i]<=122)s3[i]-=32;
   }
   if(M[s3]==0){c++;M[s3]=c;y=c;}
   else y=M[s3];
   if(M[s1]==0){c++;M[s1]=c;x=c;}
   else x=M[s1];
   G[x].pb(y);
   G[y].pb(x);
 }
 dfs(1,0);
 cout << ans << endl;
 return 0;
 }
