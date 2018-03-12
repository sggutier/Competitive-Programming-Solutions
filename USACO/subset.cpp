/*
ID: me60
LANG: C++11
TASK: subset
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    
    int N, sum;

    scanf("%d", &N);
    sum = (N*(N+1))/2;
    long long sumas[sum + 1];

    memset(sumas, 0, sizeof(sumas));
    sumas[0] = 1LL;
    for(int i=1; i<=N; i++) {
        for(int j=sum-i; j>=0; j--) {
            sumas[i+j] += sumas[j];
        }
    }

    printf("%lld\n", sum%2==0? sumas[sum/2]/2  : 0LL);
    
    return 0;
}
