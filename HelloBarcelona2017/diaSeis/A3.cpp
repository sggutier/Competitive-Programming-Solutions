#include <bits/stdc++.h>
using namespace std;

int n, arr[300000], r[300000];

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    for(int i=0; i<n;){
        if(arr[i]==0){
            r[i++]=0;
        }
        else{
            int act = arr[i], j=i;
            while(act>0){
                r[i]=arr[j]-act + 1;
                i++;
                act--;
            }
        }
    }

    for(int i=0; i<n; i++)
        printf("%d ",r[i]);
    printf("\n");
    return 0;
}
