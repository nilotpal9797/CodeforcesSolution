//Problem link:-https://www.hackerrank.com/challenges/maxsubarray
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;int n,i;
    scanf("%d",&t);
    while(t--)
        {
          scanf("%d",&n);
          int arr[n];int temp=0,max=0,sum=0;
          for(i=0;i<n;i++)
              scanf("%d",&arr[i]);
        for(i=0;i<n;i++){
              temp+=arr[i];
            if(temp<0)
                temp=0;
            if(temp>max)
                 max=temp;
        }
        for(i=0;i<n;i++)
            if(arr[i]>0)
             sum+=arr[i];
            if(sum==0){sum=-100000;
             for(i=0;i<n;i++)
                 if(arr[i]>sum)
                   sum=arr[i];
                 max=sum;
        }
        printf("%d %d\n",max,sum);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
