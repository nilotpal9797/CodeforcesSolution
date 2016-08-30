//problem link:- http://www.codeforces.com/problemset/problem/711/A
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
  char arr[1001][5];
  for(int i=0;i<n;i++)
    for(int j=0;j<5;j++)
      cin>> arr[i][j];
  int f=0;
  int r,c;
  for(int i=0;i<n;i++)
    if(arr[i][0]=='O' && arr[i][1]=='O' ){f=1;r=i;c=0;break;}
    else if(arr[i][3]=='O' && arr[i][4]=='O'){f=1;r=i;c=3;break;}
 if(!f)cout << "NO\n";
 else{
       cout << "YES\n";
       arr[r][c]='+';
       arr[r][c+1]='+';
       for(int i=0;i<n;i++){
        for(int j=0;j<5;j++)
         cout << arr[i][j];
         cout << endl;
       }
 }
  return 0;
}
