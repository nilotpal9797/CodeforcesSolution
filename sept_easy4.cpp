#include<bits/stdc++.h>
using namespace std;

int arr[1002];
int vis[1002]={0};

int n;
int main(){
   cin >> n;
   int s,e;
   int f=0;
   for(int i=1;i<=n;i++)
   	 cin >> arr[i];
   cin >> s >> e;
   while(1){
   	if(s==e){f=1;break;}
    if(vis[s]==1)break;
    vis[s]=1;
    s=arr[s];
   }
   if(f)cout << "Yes\n";
   else cout << "No\n";
	return 0;
}
