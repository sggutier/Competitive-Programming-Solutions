#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM_N = 22;

int N, R ;
double probs[LIM_N];
double tabL[LIM_N][LIM_N];
double tabR[LIM_N][LIM_N];

void calcTabl(int ini, int fin, int dir, double ans[LIM_N][LIM_N]) {
    ans[ini][0] = 1 ;
    for(int i=1; i <= R; i++) {
        ans[ini][i] = 0 ;
    }
    for(int i=ini+dir; i != fin; i += dir) {
        double a = probs[i], na = 1 - a;
        ans[i][0] = ans[i-dir][0] * na;
        for(int j=1; j <= R; j++) {
            ans[i][j] = ans[i-dir][j-1] * a + ans[i-dir][j] * na ;
        }
    }
}

void testCase() {
    for(int i=1; i <= N; i++) {
        scanf("%lf", &probs[i]);
    }
    if(R == 0) {
        for(int i=0; i < N; i++) {
            printf("0.000000\n");
        }
        return ;
    }
    calcTabl(0, N+1,  1, tabL);
    calcTabl(N+1, 0, -1, tabR);
    double probR = tabL[N][R];
    int S = R-1;
    for(int i=1; i <= N; i++) {
        double pinv = 0 ;
        for(int x=0, y=S; x <= S; x++, y--) {
            pinv += tabL[i-1][x] * tabR[i+1][y];
        }
        printf("%.6lf\n", pinv * probs[i] / probR);
    }
}

int main() {
    int tc = 0 ;
    while(scanf("%d%d", &N, &R) != EOF && N) {
        printf("Case %d:\n", ++tc);
        testCase();
    }
}
