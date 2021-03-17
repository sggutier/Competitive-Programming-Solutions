#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bkCnt = 1;
ll sms[25], bks[25];

inline ll cub(const ll x) {
    return x*x*x;
}

ll getRt(const ll k) {
    ll x = powl(k, 1.0 / 3);
    x = max(0LL, x - 5);
    while(x*x*x <= k)
        x++;
    x --;
    return x;
}

ll getSs(ll x) {
    int ans = 0 ;
    while(x) {
        ans ++;
        x -= cub(getRt(x));
    }
    return ans;
}

int main() {
    ll sm = 0;
    for(ll i=1; i <= 100000; i++) {
        while(cub(i) + sm < cub(i+1)) {
            sm += i*i*i;
            bks[bkCnt] = i;
            sms[bkCnt ++] = sm;
        }
    }
    sm = 0 ;
    ll n ;
    scanf("%lld", &n);
    for(int z=bkCnt-1; z > 0; z--) {
        if(sms[z] > n) continue;
        int ts = z;
        sm = sms[z];
        for(int k=z; k; k--) {
            for(ll d=1; d; d--) {
                while(getSs(sm - cub(bks[k]) + cub(bks[k]+d)) == ts) {
                    ll nov = sm - cub(bks[k]) + cub(bks[k]+d);
                    if(n < nov) break;
                    sm = nov;
                    bks[k] += d;
                }
            }
        }
        break;
    }
    printf("%lld %lld\n", getSs(sm), sm);
}
