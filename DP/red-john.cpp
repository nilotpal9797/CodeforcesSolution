//Problem link:-https://www.hackerrank.com/challenges/red-john-is-back
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[50];
ll solve(int n){
  if(n>=0){
  if(dp[n]!=-1)return dp[n];}
  if(n<0)return 0;
  if(n==0)return 1;
  ll ans=solve(n-1)+solve(n-4);
  if(n>=0)
  return dp[n]=ans;
  return 0;
}

int pr[3000000]={0};
ll cnt[3000000]={0};

int main(){
 int t,n;
 ll x=sqrt(2700000);
 for(int i=3;i<=x+2;i+=2)
  if(!pr[i])
   for(int j=i*i;j<=2700000;j+=2*i)
    pr[j]=1;
  cnt[0]=0;
  cnt[1]=0;
  cnt[2]=1;
 for(int i=3;i<=2700000;i++)
  if(i%2==0)
   cnt[i]=cnt[i-1];
  else if(pr[i]==0)cnt[i]=1+cnt[i-1];
  else cnt[i]=cnt[i-1];
 cin >> t;
 memset(dp,-1,sizeof(dp));
 dp[0]=1;
 while(t--){
 cin>>n;
 ll p=(solve(n));
 cout << cnt[p]<<endl;
}
  return 0;
}
