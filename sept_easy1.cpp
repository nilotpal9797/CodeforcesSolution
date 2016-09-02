#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int> M;
#define pb push_back
vector<int> G[200005];

int main(){
  ll arr[200005];
  int n;int l;
  cin >> n;
  int c=0;
  for(int i=0;i<n;i++){
   cin >> arr[i];
   if(M[arr[i]]==0){
     c++;
     M[arr[i]]=c;
    }
   G[M[arr[i]]].pb(i);
   }
   ll ans=1;
   int count[200005];
   int c2[200005]={0};
   int last=-1;
   for(int i=0;i<n;i++){
     if(c2[M[arr[i]]]==0){
      c2[M[arr[i]]]++;
      last=i;
     }
   }
  // cout << "last is "<<last<<endl;
   memset(count,0,sizeof(count));
   ll x;
   ans=(n-last);
   int f=0;l=last;
   int idx;
   for(int i=1;i<n;i++){
     x=M[arr[i-1]];
     count[x]++;
     if(G[x].size()<count[x]+1){
       break;
     }
     idx=G[x][count[x]];
     //cout << "x and idx are "<<x<<" "<<idx<<endl; 
     if(idx>last){
       last=idx;
     }
     ans+=((n-last));
   }
  cout << ans << endl;
  return 0;
 }
