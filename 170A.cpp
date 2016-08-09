http://codeforces.com/problemset/problem/277/A
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
int vis[102]={0};
int par[102];
int in[102]={0};

int find(int a){
	if(par[a]!=a)par[a]=find(par[a]);
	return par[a];
}


void unioni(int a,int b){
 int p1=find(a);
 int p2=find(b);
 if(p1!=p2){
  par[p2]=p1;
  }
}

int main(){
	int n,m;int c=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		par[i]=i;
	}
	int z=0,x,y;
	int pre;
	for(int i=0;i<n;i++){
		cin >> x;
		if(x==0)z++;
		else{
			  for(int j=1;j<=x;j++){
			  	  if(j==1){
			  	  	cin >> y;
			  	  	in[y]=1;
			  	  	pre=y;
			  	  }
			  	  else{
			  	  	cin >> y;
			  	  	in[y]=1;
			  	  	unioni(y,pre);
			  	  	pre=y;
			  	  }
			  }
		}
	}
 for(int i=1;i<=m;i++){
 	 int a=find(i);
 	 if(vis[a]==0 && in[a]==1){
 	 	c++;
 	 	vis[a]=1;
 	 }
  }
 if(c>0)c--;
cout << z+c<< endl;
return 0;
}
