#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T, A, N, R, X[10005], H[10005], HDP[10005], lo, hi, acu;

int main() {
    scanf("%lld", &T);

    while(T--) {
        scanf("%lld %lld", &A, &N);

        for(ll i=0;i<N;i++)
            scanf("%lld", &X[i]);

        for(ll i=0;i<=N;i++)
            scanf("%lld", &H[i]);

        HDP[N] = H[N];

        for(ll i=N-1;i>=0;i--)
            HDP[i] = max(HDP[i+1], H[i]);

        R = lo = 0;

        while(lo < N) {
            hi = lo + 1, acu = X[lo];

            while(H[hi] < H[lo] && H[hi] != HDP[hi])
                acu += X[hi++];

            R += acu * min(H[lo], H[hi]);
            lo = hi;
        }

        R *= A;

        printf("%lld\n", R);
    }

    return 0;
}
