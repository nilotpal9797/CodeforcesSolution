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
 int n;
 cin >> n;
 ll arr[300005];
 ll s=0,t=0;
 for(int i=0;i<n;i++){
  cin >> arr[i];s+=arr[i];}
 sort(arr,arr+n);
 ll p=0;
 ll yo;
 ll ans=999999999999999;
 for(int i=0;i<n;i++){
    t+=arr[i];
    p=s-t;
    if((arr[i]*(i+1-(n-i-1))+(p-t))<ans){
      yo=arr[i];
      ans=(arr[i]*(i+1-(n-i-1))+(p-t));
   }
 }
 cout << yo << endl;
 return 0;
}
