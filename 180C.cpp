#include<bits/stdc++.h>
using namespace std;

int main(){
 char arr[100005];
 scanf("%s",arr);
 int ans=INT_MAX;
 int l=strlen(arr);
 int pre[100005]={0};
 int suf[100005]={0};
 if(arr[0]>90)pre[0]=1;
 for(int i=1;i<l;i++)
  if(arr[i]>90)pre[i]=1+pre[i-1];
  else pre[i]=pre[i-1];
 if(arr[l-1]<=90)suf[l-1]=1;
 for(int i=l-2;i>=0;i--)
  if(arr[i]<=90)suf[i]=suf[i+1]+1;
  else suf[i]=suf[i+1];
 for(int i=-1;i<l;i++){
    if(i==-1)ans=min(ans,suf[0]);
    else if(i==l-1)ans=min(pre[l-1],ans);
    else ans=min(ans,pre[i]+suf[i+1]);
  }
 cout << ans << endl;
 return 0;
}
