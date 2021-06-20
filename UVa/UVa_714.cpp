#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 505;
const ll INF = 1e18 ;

int N ;
ll nums[LIM_N];
int sigP[LIM_N][LIM_N];
ll dp[LIM_N][LIM_N];

ll memo(int pos, int rem) {
    if(pos == N) {
        return rem? INF : 0;
    }
    if(rem == 0) {
        return INF ;
    }
    if(sigP[pos][rem]) {
        return dp[pos][rem];
    }
    ll sm = 0;
    ll &ans = dp[pos][rem];
    ans = INF + 1 ;
    for(int i=pos; i < N; i++) {
        sm += nums[i];
        ll k = max(sm, memo(i+1, rem-1));
        if(k < ans) {
            sigP[pos][rem] = i + 1;
            ans = k;
        }
    }
    return ans ;
}

void testCase() {
    memset(sigP, 0, sizeof(sigP));
    int K ;
    ll maxSec ;
    scanf("%d%d", &N, &K);
    for(int i=0; i < N; i++)
        scanf("%lld", &nums[i]);
    maxSec = memo(0, K);
    // memo(0, K);
    for(int i=0; K > 0; K--) {
        if(i)
            printf(" /");
        ll curSec = 0 ;
        for(int sp = sigP[i][K]; i < sp; i++) {
            if(i) {
                printf(" ");
            }
            printf("%lld", nums[i]);
            curSec += nums[i];
        }
        if(curSec >= maxSec) {
            K -- ;
            for(; K > 0; K--) {
                printf(" /");
                int j ;
                for(j=i+1; j < N; j++) {
                    if(memo(j, K-1) <= maxSec)
                        break;
                }
                for(; i < j; i++)
                    printf(" %lld", nums[i]);
            }
            for(; i < N; i++)
                printf(" %lld", nums[i]);
        }
    }
    printf("\n");
}

int main() {
    int tc ;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
