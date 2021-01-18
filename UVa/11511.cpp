#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 1005;

ll _cur[LIM_N], _sig[LIM_N];

void testCase(int N) {
    int r, c ;
    ll *cur = _cur, *sig = _sig;
    scanf("%d%d", &r, &c);
    for(int i=0; i < N; i++)
        scanf("%lld", &cur[i]);
    r--, c--;
    c %= N+1 ;
    for(int j=0; j < c; j++, swap(cur, sig)) {
        sig[0] = sig[N-1] = 1 ;
        for(int i=1; i + 1 < N; i++) {
            sig[i] = (sig[i-1] * cur[i+1] + 1) / cur[i];
        }
    }
    printf("%lld\n", cur[r]);
}

int main() {
    int N ;
    while(scanf("%d", &N)!=EOF && N) {
        testCase(N);
    }
}
