#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int limN = 1e5 + 5;

ll potMod(const ll x, const ll p) {
    if(p==0)
        return 1;
    if(p==1)
        return x % mod;
    ll mt = potMod(x, p/2);
    return ( ((mt*mt)%mod) * (p%2? x : 1) ) % mod;
}

int main() {
    int N ;
    ll x, s = 0, maxP = 0 ;
    ll nums[limN];
    map <ll, int> reps;

    scanf("%d%lld", &N, &x);
    for(int i=0; i<N; i++) {
        scanf("%lld", &nums[i]);
        maxP = max(maxP, nums[i]);
        s += nums[i];
    }
    for(int i=0; i<N; i++) {
        reps[maxP - nums[i]]++;
    }

    auto it = reps.begin();
    while(it->second % x == 0) {
        reps[it->first + 1] += it->second / x;
        it++;
    }
    // printf("s = %lld\n", s);

    printf("%lld\n", potMod(x, s + min(it->first, maxP) - maxP) );
}
