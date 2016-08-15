http://www.codeforces.com/problemset/problem/380/C
#include<bits/stdc++.h>
using namespace std;

struct node{
  int ans;
  int open;
  int close;
};

struct node st[4*1000005];
char arr[1000005];
node zero={0,0,0};
void buildTree(int s,int e,int idx){
  if(s==e){
     if(arr[s]=='('){
       st[idx].ans=0;
       st[idx].open=1;
       st[idx].close=0;
     }
    else{
         st[idx].ans=0;
         st[idx].open=0;
         st[idx].close=1;
    }
   return;
  }
 else{
       int mid=(s+e)/2;
       buildTree(s,mid,2*idx+1);
       buildTree(mid+1,e,2*idx+2);
       int t=min(st[2*idx+1].open,st[2*idx+2].close);
       st[idx].ans=st[2*idx+1].ans+st[2*idx+2].ans+2*t;
       st[idx].open=st[2*idx+1].open+st[2*idx+2].open-t;
       st[idx].close=st[2*idx+1].close+st[2*idx+2].close-t;
   }
}

node qry(int s,int e,int idx,int l,int r){
 if(s>=l && e<=r)return st[idx];
 else if(l>e || r<s)return zero;
 else{
       int mid=(s+e)/2;
       node t1,t2,res;
       t1=qry(s,mid,2*idx+1,l,r);
       t2=qry(mid+1,e,2*idx+2,l,r);
       int tmp=min(t1.open,t2.close);
       res.ans=t1.ans+t2.ans+2*tmp;
       res.open=t1.open+t2.open-tmp;
       res.close=t1.close+t2.close-tmp;
       return res;

  }
}

int main(){
 scanf("%s",arr);
 int l=strlen(arr);
 buildTree(0,l-1,0);
 int n,x,y;
 scanf("%d",&n);
 while(n--){
   cin >> x >> y;
   x--;y--;
   node answer=qry(0,l-1,0,x,y);
   cout << answer.ans << endl;
  }
 return 0;
}
