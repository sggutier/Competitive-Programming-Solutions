#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 20;

ll facts[LIM_N];

void init() {
    facts[0] = 1 ;
    for(ll i=1; i < LIM_N; i++)
        facts[i] = i * facts[i-1];
}

void calcPerm(ll p, int N, int* ans) {
    p -- ;
    bool usd[LIM_N] = {0};
    for(int i=0, k=N-1; i < N; i++, k--) {
        int w = p / facts[k];
        // printf("%lld %d\n", p, w);
        p -= w * facts[k];
        for(int j=0; ; j++) {
            if(usd[j]) continue;
            if(w == 0) {
                ans[i] = j ;
                usd[j] = true;
                break;
            }
            w -- ;
        }
    }
    // for(int i=0; i < N; i++)
    //     printf("%d ", ans[i]);
    // printf("\n");
}

void testCase() {
    char s[LIM_N + 5];
    int N, perm[LIM_N] ;
    char rev[LIM_N + 5];
    ll p ;
    scanf("%s%lld", s, &p);
    N = strlen(s);
    calcPerm(p, N, perm);
    for(int i=0; i < N; i++) {
        rev[perm[i]] = s[i];
    }
    rev[N] = 0;
    printf("%s\n", rev);
}

int main() {
    // cin.sync_with_stdio(0); cin.tie(0);
    // cin.exceptions(cin.failbit);
    init();
    int tc ;
    scanf("%d", &tc);
    for(int i=1; i <= tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}
