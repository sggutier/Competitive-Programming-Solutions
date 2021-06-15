#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void testCase() {
    int N ;
    map <ll,ll> reps, invs;
    scanf("%d", &N);
    for(int i=0, a; i < N; i++) {
        scanf("%d", &a);
        reps[a]++;
    }
    ll ltSm = 0, btSm = 0;
    for(const auto &p : reps) {
        btSm += p.second;
        invs[p.second] ++;
    }
    ll ans = btSm;
    ll btCnt = 0 ;
    for(const auto &p : invs)
        btCnt += p.second;
    for(const auto &p : invs) {
        btSm -= p.first * p.second;
        btCnt -= p.second ;
        ans = min(ans, ltSm + btSm - btCnt * p.first);
        // printf("%lld %lld  |  ", p.first, p.second);
        // printf("%lld %lld %lld > %lld\n", ltSm, btSm, btCnt, ltSm + btSm - btCnt * p.first);
        ltSm += p.first * p.second;
    }
    printf("%lld\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i < tc; i++)
        testCase();
}
