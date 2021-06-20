#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll inf = 1e9;

ll lcm(ll a, ll b) {
    return (a/__gcd(a,b))*b;
}

void testCase(int coinCnt, int querCnt) {
    set <ll> combs;
    ll coins[100];

    for(int i=0; i<coinCnt; i++) {
        scanf("%d", &coins[i]);
    }

    for(int i=0; i<coinCnt; i++) {
        for(int j=i+1; j<coinCnt; j++) {
            for(int k=j+1; k<coinCnt; k++) {
                for(int w=k+1; w<coinCnt; w++) {
                    combs.insert(lcm(lcm(coins[i], coins[j]), lcm(coins[k], coins[w])));
                }
            }
        }
    }

    while(querCnt--) {
        ll w;
        ll mino=0, maxo=inf;
        scanf("%d", &w);
        for(const ll &c:combs) {
            if(c>w) {
                maxo = min(maxo, c);
                break;
            }
            mino = max(mino, (w/c)*c);
            maxo = min(maxo, (w/c + (w%c? 1 : 0)) * c);
        }
        printf("%d %d\n", mino, maxo);
    }
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
}
