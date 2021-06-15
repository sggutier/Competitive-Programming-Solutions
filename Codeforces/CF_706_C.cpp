#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;
const ll inf = 1e18;

int csts[limN];
long long dp[limN][2];
string strs[limN][2];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int N;

    cin >> N ;
    for(int i=0; i<N; i++)
        cin >> csts[i];
    for(int i=0; i<N; i++) {
        cin >> strs[i][0];
        strs[i][1] = strs[i][0];
        reverse(strs[i][1].begin(), strs[i][1].end());
    }

    dp[N-1][1] = csts[N-1];
    for(int i=N-2; i>=0; i--) {        
        for(int j=0; j<2; j++) {
            dp[i][j] = inf;
            for(int k = 0; k<2; k++) {
                if(strs[i][j] <= strs[i+1][k])
                    dp[i][j] = min(dp[i][j], dp[i+1][k]);
            }
        }
        dp[i][1] = min(inf, dp[i][1] +csts[i]);
    }

    ll ans = min(dp[0][0], dp[0][1]);
    printf("%lld\n", ans==inf? -1 : ans);
}
