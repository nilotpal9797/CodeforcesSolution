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

typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef vector<int> vi;

vector<int> s;
int prime[3200000]={0};
int main(){
 vector<pair<ll,ll> > v;
 ll c=0;
 s.pb(2);
 ll i,j;
 for(i=3;i<=1800;i+=2)
  if(!prime[i])
   for(j=i*i;j<3200000;j+=(2*i))
    prime[j]=1;
 for(j=3;j<3200000;j+=2)
  if(!prime[j])
   s.pb(j);
 ll q;
 cin >> q;
 for( i=0;i<s.size();i++){
    if(s[i]>q)break;
    else{
          c=0;
          if(q%s[i]==0){
             while(q%s[i]==0){
                c++;
                q/=s[i];
             }
             v.pb(mp(s[i],c));
          }
    }
 }
 if(q>1)v.pb(mp(q,1));
 //cout << "size of v is "<<v.size()<<endl;
 //cout<<"v[0].X is "<<v[0].X<<endl;
 //cout << "v[1].X is "<<v[1].X<<endl;
 if(v.size()>=3){
    cout << "1"<<endl;
    cout << v[0].X*v[1].X<<endl;
  }
 else if(v.size()==0){
    cout << "1"<<endl;
    cout << "0"<< endl;
 }
 else if(v.size()==2 && v[0].Y==1 && v[1].Y==1)
  cout << "2"<< endl;
 else if(v.size()==1 && v[0].Y==1){
    cout << "1"<<endl;
    cout << "0"<<endl;
 }
 else{
        if(v.size()==1 && v[0].Y==2){
            cout << "2"<<endl;
        }
       else if(v.size()==1){
          cout <<"1"<<endl;
          cout<< (v[0].X)*(v[0].X)<<endl;
       }
     else if(v.size()==2 ){cout << "1"<<endl;cout<<v[0].X*(v[1].X)<<endl;}
     else{
        cout << "1"<<endl;
        cout << v[0].X*v[0].X << endl;
     }
 }
 return 0;
}
