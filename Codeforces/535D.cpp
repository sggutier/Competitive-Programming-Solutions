#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 1e6 + 5;

ll pots[limN];
ll nums[limN];
int poss[limN];
char str[limN];
bool ini[limN];

int main() {
    int K, N, M ;
    ll ans = 1;

    scanf("%d%d", &K, &M);
    scanf("%s", str);
    N = strlen(str);
    for(int i=0; i<M; i++) {
        scanf("%d", &poss[i]);
        poss[i]--;
        ini[poss[i]] = true;
    }

    pots[0] = 1;
    nums[0] = 0;
    for(int i=0; i<N; i++) {
        pots[i+1] = (pots[i]*26)%mod;
        nums[i+1] = (nums[i]*26 + str[i]-'a')%mod;
    }

    for(int i=1; i<M; i++) {
        int t = N - (poss[i]-poss[i-1]), d = poss[i]-poss[i-1];
        if(t <= 0)
            continue;
        if(nums[t] != (nums[N]+(mod - (nums[d]*pots[t])%mod))%mod ) {
            printf("0\n");
            return 0;
        }
    }

    for(int i=0, r=0; i<K; i++) {
        if(ini[i]) r = N;
        if(r <= 0)
            ans = (ans*26)%mod;
        r --;
    }

    printf("%lld\n", ans);
}
