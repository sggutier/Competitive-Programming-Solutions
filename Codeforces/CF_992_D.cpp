#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double logmax = log(2e18);
const int limN = 2e5 + 5;

ll sums[limN];

int main() {
    int N;
    ll k;
    vector <int> not1P;
    ll arr[limN];
    ll ans = 0;
    scanf("%d%lld", &N, &k);
    not1P.push_back(0);
    for(int i=1; i<=N; i++) {
        scanf("%lld", &arr[i]);
        sums[i] = sums[i-1] + arr[i];        
        if(arr[i] > 1)
            not1P.push_back(i);
    }

    int W = not1P.size();
    for(int i=1, w=0; i<=N; i++) {
        ll p = 1, d;
        while(w < W && not1P[w] <= i)
            w++;
        if(arr[i]==1 && k==1)
            ans ++;
        // printf("%d %d (%d)\n", i, w, w<W? not1P[w] : -1);
        for(int j=w-1, a; j>0; j--) {
            a = not1P[j];
            if(log(p) + log(arr[a]) > logmax)
                break;
            p *= arr[a];
            d = a - not1P[j-1] - 1;
            // printf("\t %d %d => %lld %lld\n", a, i, p, sums[i]-sums[a-1]);
            if( p%k==0 && k*(sums[i] - sums[a-1]) <= p &&  p <= k*(sums[i] - sums[a-1]+d) ) {
                ans ++;
                // printf("\t yeh \n");
            }
        }
    }

    printf("%lld\n", ans);
}
