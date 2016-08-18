#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fac[11];
void makefac(){
  fac[0]=1;
  for(int i=1;i<11;i++)
   fac[i]=i*fac[i-1];
}

int main(){
  makefac();
 string s1,s2;
 cin >> s1;
 int l1=s1.length();
 cin >> s2;
 int p1=0,m1=0;
 int p2=0,m2=0,q2=0;
 for(int i=0;i<l1;i++)
   if(s1[i]=='+')p1++;
   else m1++;
 for(int i=0;i<l1;i++){
    if(s2[i]=='+')p2++;
    else if(s2[i]=='-')m2++;
    else q2++;
  }
  double ans;
 if(p2>p1 || m2>m1)ans=0;
 else ans=(((fac[q2]*1.0)/((fac[p1-p2]*1.0)*fac[m1-m2]))/(pow(2,q2)*1.0));
 printf("%0.13lf\n",ans);
 return 0;
}
