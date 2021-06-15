#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 18;
const int limB = 1<<limN;
const int limM = 100;

int N, mod ;
bool usd[limB][limM];
ll waysMemo[limB][limM];
int pots[limN + 1];
ll fact[limN + 1];
int reps[15], cur[15];

ll ways(int msk, int pos, int sum) {
    if(pos < 0)
        return sum == 0? 1 : 0;
    if(usd[msk][sum])
        return waysMemo[msk][sum];
    usd[msk][sum] = true;
    ll &ans = waysMemo[msk][sum];
    for(int i=0; i<10; i++) {
        if(reps[i] != cur[i]) {
            cur[i]++;
            ans += ways(msk - (1<<(cur[i]-1)), pos-1, (sum + pots[pos]*i)%mod );
            cur[i]--;
        }
    }
    return ans;
}

int main() {
    ll ans = 0;
    char str[limN+5];
    
    scanf("%s%d", str, &mod);
    N = strlen(str);
    for(int i=0; i<N; i++) {
        str[i] -= '0';
        reps[(int) str[i]]++;
    }

    pots[0] = 1;
    for(int i=1; i<=N; i++) {
        pots[i] = (pots[i-1]*10)%mod;
    }
    cur[0] = 0;
    for(int i=1; i<10; i++) {
        reps[i] += reps[i-1];
        cur[i] = reps[i-1];
    }

    for(int i=1; i<10; i++)
        if(reps[i] != cur[i]) {
            cur[i]++;
            ans += ways((1<<N)-1 - (1<<(cur[i]-1)), N-2, (pots[N-1]*i)%mod );
            cur[i]--;
        }

    printf("%lld\n", ans);
}
