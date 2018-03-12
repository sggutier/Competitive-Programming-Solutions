#include <bits/stdc++.h>
using namespace std;
const int limN = 5e5 + 5;
typedef long long ll;

int N ;
ll arr[limN];
ll waysL[limN];

int main() {
    ll t = 0;
    ll ans = 0;
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%lld", &arr[i]);
        t += arr[i];
    }

    if(t%3) {
        printf("0\n");
        return 0;
    }
    t /= 3;

    ll s = 0;
    for(int i=1; i<=N; i++) {
        s += arr[i];
        waysL[i] = waysL[i-1];
        if(s==t)
            waysL[i]++;
    }
    s = 0;
    for(int i=N; i>=2; i--) {
        s += arr[i];
        if(s==t)
            ans += waysL[i-2];
    }

    // for(int i=1; i<=N; i++)
    //     printf("%lld ", waysL[i]);
    // printf("\n");
    // for(int i=1; i<=N; i++)
    //     printf("%lld ", waysR[i]);
    // printf("\n");

    // for(int i=1; i+2<=N; i++) {
    //     ans += waysL[i]*waysR[i+2];
    // }

    printf("%lld\n", ans);
}
