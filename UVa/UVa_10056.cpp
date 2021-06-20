#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void testCase() {
    int N ;
    double p, q, ans = 1;
    int pos ;
    scanf("%d%lf%d", &N, &p, &pos);
    if(p == 0) {
        printf("0.0000\n");
        return ;
    }
    q = 1 - p ;
    for(int i=0; i < N; i++) {
        ans *= q ;
    }
    ans = 1 / (1 - ans);
    ans *= p ;
    for(int i=1; i < pos; i++, ans *= q);
    printf("%.4lf\n", ans);
}

int main() {
    int tc ;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
