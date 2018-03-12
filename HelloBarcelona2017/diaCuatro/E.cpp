#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d %d",&a,&b);
    printf("%d\n",(n-1)/2);
    return 0;
}
