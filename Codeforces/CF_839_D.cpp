#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6;
typedef long long ll;
const ll mod = 1000000007;

ll ans[limN + 5];
int cnts[limN + 5];
// list <int> divs[limN + 5];
int nums[limN + 5];
ll pots2[limN + 5];

void marca() {
    pots2[0] = 1;
    pots2[1] = 2;
    for(int i=2; i<=limN; i++) {
        pots2[i] = (2 * pots2[i-1]) % mod;
        // for(int j=i; j<=limN; j+=i)
        //     divs[j].push_back(i);
    }    
}


int main() {
    marca();
    
    int N ;
    
    scanf("%d", &N);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        nums[a] ++;
    }
    for(int i=2, w; i<=limN; i++)
        if(nums[i]) {
            // for(const int d : divs[i])
            //     cnts[d] += nums[i];
            for(w=1; w*w < i; w++) {
                if(i % w == 0) {
                    // printf("%d => %d\n", i, w);
                    // printf("%d => %d\n", i, i/w);
                    cnts[w] += nums[i];
                    cnts[i/w] += nums[i];
                }
            }
            if(w*w == i)
                cnts[w] += nums[i];
        }

    ll tt = 0;
    for(int i=limN; i>=2; i--) {
        if(cnts[i]) {
            // printf("%d => %d %lld\n", i, cnts[i], pots2[cnts[i] -1 ]);
            ans[i] = (cnts[i] * pots2[cnts[i] -1 ]) % mod;
            for(int j=2*i; j<=limN; j+=i) {
                // if(ans[j])
                //     printf("\t < %lld\n", ans[j]);
                ans[i] = (ans[i] + mod - ans[j]) % mod;
            }
            // printf("\t %lld\n", ans[i]);
            tt = (tt + ans[i] * i) % mod;
        }
    }

    printf("%lld\n", tt);
}
