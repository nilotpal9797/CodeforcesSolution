#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  char arr[102];
  scanf("%s",arr);
  int l=strlen(arr);
  int b=0,s=0,c=0;
  for(int i=0;i<l;i++){
     if(arr[i]=='B')b++;
     else if(arr[i]=='S')s++;
     else c++;
  }
  ll nb,ns,nc;
  ll pb,ps,pc;
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  ll r;
  cin >> r;
  ll x;
  ll lo=0,hi=2000000000005;
  while(lo<hi){
      ll mid=(lo+hi+1)/2;
      x=0;
      if(mid*b-nb >0)x+=(mid*b-nb)*pb;
      if(mid*s-ns >0)x+=(mid*s-ns)*ps;
      if(mid*c-nc >0)x+=(mid*c-nc)*pc;
      if(x>r) hi=mid-1;
      else lo=mid;
  }
 cout << lo << endl;
  return 0;
}
