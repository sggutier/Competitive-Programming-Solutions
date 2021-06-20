#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 105;

double dp[LIM_N][LIM_N][LIM_N];
bool usd[LIM_N][LIM_N][LIM_N];

double memo(int n, int m, int f=0) {
    if(usd[n][m][f])
        return dp[n][m][f];
    usd[n][m][f] = true;
    if(n == 0)
        return dp[n][m][f] = m? 1.0 : 0.0;
    if(m == 0)
        return dp[n][m][f] = 0.0;
    double tt = m + f ;
    return dp[n][m][f] =
        memo(n-1, m-1, f+1) * (m / tt)  +
        memo(n-1, m, f) * (f / tt);
}

int main() {
    int n, m ;
    int tc = 0 ;
    while(scanf("%d", &n) != EOF && n != -1) {
        scanf("%d", &m);
        printf("Case %d: %.7lf\n", ++tc, memo(n, m));
    }
}
