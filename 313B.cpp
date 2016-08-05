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

int main(){
 int n,m,l,r;
 char arr[100005];
 ll ans[100005]={0};
 scanf("%s",arr);
 n=strlen(arr);
 for(int i=0;i<n-1;i++){
   if(arr[i]==arr[i+1])
    ans[i+1]=1;
 }
 for(int i=1;i<=n;i++)
  ans[i]+=ans[i-1];
 cin >> m;
 while(m--){
   cin >> l >> r;
   l--;r--;
   if(l==0)cout << ans[r] << endl;
   else cout << ans[r]-ans[l]<<endl;
 }
  return 0;
}
