//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//
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
#define MOD 1000000007

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef vector<int> vi;

ll exp(ll a,ll b,ll m){
  if(b==0)return 1%m;
  else if(b==1)return a%m;
  else{
    ll x=(exp(a,b/2,m))%m;
    x=(x*x)%m;
    if((b%2)==1)x=(x*(a%m))%m;
    return x;
  }
}


int main(){
 int t;
 ll cp=0;
 cin >> t;
 while(t--){
   cp++;
 ll a,b,n,k;
 cin >> a >> b >> n >> k;
 //cout << a <<" "<<b << " "<<n <<" "<<k;
 ll rem1[100005];
 ll rem2[100005];
 ll block,rem;
 if(n>=k)
 for(int i=1; i<=k;i++){
  rem1[i]=exp(i%k,a,k);
  rem2[i]=exp(i%k,b,k);
 }
 else{
   for(int i=1; i<=n;i++){
    rem1[i]=exp(i%k,a,k);
    rem2[i]=exp(i%k,b,k);}
 }
 if(n>=k)block=(n/k);
 else block=0;
 rem=n%k;
 ll rem3[100005]={0};
 ll rem4[100005]={0};
 //fill(rem3,rem3+100005,0);
 //fill(rem4,rem4+100005,0);
 if(block>=1)
 for(int i=1;i<=k;i++)
  {
      rem3[rem1[i]]++;
      rem4[rem2[i]]++;
  }
 else{
   for(int i=1;i<=n;i++)
    {
        rem3[rem1[i]]++;
        rem4[rem2[i]]++;
    }
 }
 if(block>=1){
    for(int i=0;i<k;i++)
     {
        rem3[i]=rem3[i]*block;
        rem4[i]=rem4[i]*block;
     }
    if(rem>0){
        for(int i=1;i<=rem;i++){
           rem3[rem1[i]]++;
           rem4[rem2[i]]++;
        }
    }
 }
 //cout << "printing rem1"<<endl;
 //for(int i=0; i<k;i++)
  //cout << rem3[i] <<" "<<rem4[i]<<endl;
 ll ans=0;
 ll ans1=0;
 //cout << "ans here is "<<ans << endl;
 for(int i=0;i<k;i++){
   //cout << "rem3 "<<i<<" "<<rem3[i];
   if(i==0)ans=(ans%MOD+(rem3[0]*rem4[0])%MOD)%MOD;
   else
   ans=(ans%MOD+(rem3[i]*(rem4[k-i]))%MOD)%MOD;
 }
 //cout << "ans here is"<<ans<<endl;
 if(block>=1){
 for(int i=1;i<=k;i++)
  if((rem1[i]+rem2[i])%k==0)ans1++;
  ans1=(ans1*block)%MOD;}
  if(rem>0){
      for(int i=1;i<=rem;i++)
       if((rem1[i]+rem2[i])%k==0)ans1++;
  }
  ans=ans-ans1;
  if(ans<0)ans=ans+MOD;
  printf("Case #%lld: %lld\n",cp,ans%MOD);

 }
  return 0;
}
