#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int limK = 12;
typedef long long ll;

struct BIT {
    const int N = limN;
    ll nums[limN];
    void mete(int pos, ll nov) {
        for(; pos<N; pos+=(pos & -pos))
            nums[pos] += nov;
    }
    ll saca(int pos) {
        ll ans = 0;
        for(; pos>0; pos-=(pos & -pos))
            ans += nums[pos];
        return ans;
    }
};

BIT bts[limK];

int main() {
    int N, K;

    scanf("%d%d", &N, &K);
    K ++;
    bts[0].mete(1, 1);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        a++;
        for(int j=K; j>0; j--) {
            bts[j].mete(a, bts[j-1].saca(a-1));
            // printf("%d %d => %lld %lld\n", a-1, j, bts[j].saca(a), bts[j-1].saca(a-1));
        }
    }

    printf("%lld\n", bts[K].saca(N+1));
}
