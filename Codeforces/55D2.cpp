#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int mod = 2520;
const int limD = 22;

bool usd[limD][mod][mod];
ll memo[limD][mod][mod];
int pots[limD];
set <int> lcms;

ll dp(int pos, int rem, int lcm) {
    if(lcms.count(lcm)==0) {
        lcms.insert(lcm);
        printf("%d\n", lcm);
        if(mod % lcm )
            printf("wtf\n");
    }
    if(pos==-1)
        return (rem % lcm == 0)? 1ULL : 0ULL;
    if(usd[pos][rem][lcm])
        return memo[pos][rem][lcm];
    usd[pos][rem][lcm] = true;
    for(int i=0; i<=9; i++)
        memo[pos][rem][lcm] += dp(pos-1,
                                  (rem + pots[pos]*i)%mod,
                                  (lcm*max(i, 1))/__gcd(lcm, max(i, 1)));
    // printf("%d %d %d => %d\n", pos, rem, lcm, memo[pos][rem][lcm]);
    return memo[pos][rem][lcm];
}

ll proco(char *s, int pos, int rem, int lcm) {
    // printf("proco con %s => %d %d %d\n", s, pos, rem, lcm);
    if(pos==-1)
        return 0;
    // for(int i=0; i<s[pos]-'0'; i++)
    //     printf("\tsaca de %d %d %d\n",
    //            pos-1,
    //            (rem + pots[pos]*i)%mod,
    //            (lcm*max(i, 1))/__gcd(lcm, max(i, 1)));
    ll ans = 0;
    for(int i=0; i<s[pos]-'0'; i++)
            ans += dp(pos-1,
                      (rem + pots[pos]*i)%mod,
                      (lcm*max(i, 1))/__gcd(lcm, max(i, 1)));
    return ans + proco(s, pos-1,
                       (rem + pots[pos]*(s[pos]-'0'))%mod,
                       (lcm*max(s[pos]-'0', 1))/__gcd(lcm, max(s[pos]-'0', 1)));
}

ll tc(ll b) {
    char tmp[40];
    int n ;
    sprintf(tmp, "%llu", b);
    n  = strlen(tmp);
    reverse(tmp, tmp+n);
    return proco(tmp, n-1, 0, 1);
}

int main() {
    pots[0] = 1;
    for(int i=1; i<limD; i++)
        pots[i] = (10*pots[i-1]) % mod;
    int t;
    ll a, b ;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        scanf("%llu%llu", &a, &b);
        printf("%llu\n", tc(b+1) - tc(a));
    }
}
