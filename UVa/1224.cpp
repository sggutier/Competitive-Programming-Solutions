#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM_N = 31;

ll fibs[LIM_N];
ll sims[LIM_N];

void init() {
    fibs[0] = 1;
    fibs[1] = 1;
    fibs[2] = 3;
    sims[0] = 1;
    sims[1] = 1;
    sims[2] = 3;
    for(int i=3; i < LIM_N; i++) {
        fibs[i] = fibs[i-1] + 2*fibs[i-2];
        sims[i] = sims[i-2] + (i >= 4? 2*sims[i-4] : 0);
    }
    for(int i=0; i < LIM_N; i++) {
        fibs[i] = (fibs[i] - sims[i]) / 2 + sims[i];
    }
}

int main() {
    init();
    int tc ;
    scanf("%d", &tc);
    for(int i=0, x; i < tc; i++) {
        scanf("%d", &x);
        printf("%lld\n", fibs[x]);
    }
}
