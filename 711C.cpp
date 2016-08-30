//problem link :- http://www.codeforces.com/contest/711/problem/C
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
#define M 1000000007
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef vector<int> vi;

const ll INF=9999999999999;

int arr[102];
ll color[102][102];
ll dp[102][102][102];
int k,n,m;
ll solve(int pos,int t,int col){
  if(pos==n+1){
    // cout << "t here is and k is"<<t <<" "<<k<< endl;
     if(t==k)return 0;
     else return INF;
  }
    if(dp[pos][t][col]!=-1)return dp[pos][t][col];
 else{
       if(arr[pos]!=0){
           if(arr[pos]!=col)
            return dp[pos][t][col]=solve(pos+1,t+1,arr[pos]);
           else
            return dp[pos][t][col]=solve(pos+1,t,col);
       }
      else {
              ll ans=INF;
              for(int i=1;i<=m;i++){
                  if(col==i){
                    ans=min(ans,color[pos][i]+solve(pos+1,t,col));
                  }
                  else ans=min(ans,color[pos][i]+solve(pos+1,t+1,i));
               }
           return dp[pos][t][col]=ans;
       }
   }

}


int main(){
 cin >> n >> m >> k;
 for(int i=1;i<=n;i++)
  cin >> arr[i];
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   cin >> color[i][j];
 memset(dp,-1,sizeof(dp));
 ll ans=solve(1,0,101);
 if(ans>=100000000002)cout << "-1\n";
 else cout << ans << endl;
 return 0;
}
