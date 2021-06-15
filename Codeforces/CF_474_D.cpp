#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int limN = 1e5 + 5;
// const int limN  =10;

struct BIT {
    int N = limN;
    int vals[limN];
    BIT() {
    }
    void mete(int p, int nov) {
        for(p += 2; p<N; p+=(p & -p))
            vals[p] = (vals[p] + nov) % mod;
    }
    int saca(int p) {
        int ans = 0;
        for(p+=2; p; p-=(p & -p))
            ans = (ans + vals[p]) % mod;
        return ans;
    }
};

int ways[limN];
BIT bt;

int main() {
    int Q, K;

    scanf("%d%d", &Q, &K);

    ways[0] = 1;
    bt.N = limN;
    bt.mete(0, 1);
    for(int i=1; i+3<limN; i++) {
        ways[i] = (ways[i-1] + (i>=K? ways[i-K] : 0)) % mod;
        bt.mete(i, ways[i]);
    }

    while(Q--) {
        int a, b ;
        scanf("%d%d", &a, &b);
        printf("%d\n", (bt.saca(b) + (mod - bt.saca(a-1)) ) % mod ) ;
    }
}
