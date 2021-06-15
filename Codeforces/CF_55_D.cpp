#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int mod = 2520;
const int limD = 20;
const int limB = 128;

bool usd[limD][mod][limB];
ll memo[limD][mod][limB];
int pots[limD];
int bts[] = {0, // 0
             0, // 1
             1, // 2
             8, // 3
             1 + 2, // 4
             32, // 5
             1 + 8, // 6
             64, // 7
             1 + 2 + 4, // 8
             8 + 16 };// 9;
int lcms[limB];
             

ll dp(int pos, int rem, int lcm) {
    if(pos==-1) {
        // printf("%d %d => %d\n", rem, lcm, lcms[lcm]);
        return rem % lcms[lcm] == 0;
    }
    if(usd[pos][rem][lcm])
        return memo[pos][rem][lcm];
    usd[pos][rem][lcm] = true;
    for(int i=0; i<=9; i++)
        memo[pos][rem][lcm] += dp(pos-1,
                                  (rem + pots[pos]*i)%mod,
                                  lcm | bts[i]);
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
                  lcm | bts[i]);
    return ans + proco(s, pos-1,
                       (rem + pots[pos]*(s[pos]-'0'))%mod,
                       lcm | bts[s[pos]-'0']);
}

ll tc(ll b) {
    char tmp[40];
    int n ;
    sprintf(tmp, "%llu", b);
    n  = strlen(tmp);
    reverse(tmp, tmp+n);
    return proco(tmp, n-1, 0, 0);
}

int main() {
    pots[0] = 1;
    for(int i=1; i<limD; i++)
        pots[i] = (10*pots[i-1]) % mod;
    for(int b=(1<<10)-1; b>=0; b--) {
        int m = 0, s = 1;
        for(int i=0; i<10; i++) {
            if(((1<<i) & b) == 0) continue;
            m |= bts[i];
            s = (s*max(i, 1)) / __gcd(s, max(i, 1)) ;
            // printf("%d ", i);
        }
        lcms[m] = s;
    }
    lcms[0] = 1;
    int t;
    ll a, b ;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        scanf("%llu%llu", &a, &b);
        printf("%llu\n", tc(b+1) - tc(a));
    }
}
