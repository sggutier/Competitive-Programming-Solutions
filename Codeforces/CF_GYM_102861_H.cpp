#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 50;

int N, K ;
ll cxs[LIM_N + 5];
ll pasc[LIM_N + 5][LIM_N + 5];

ll calc(ll x) {
    ll ans = 0 ;
    int w = K;
    // cout << x << " " ;
    for(int i=N-1; i >=0 && w >= 0; i--) {
        if(x >= cxs[i]) {
            // cout << x << " " << cxs[i] << " " << pasc[i][w] << " " << pasc[i][w-1] << endl;
            x -= cxs[i];
            ans += pasc[i][w];
            w -- ;
            //ans += pasc[i][w];
        }
    }
    if(w == 0) {
        ans ++ ;
    }
    // cout << ans << endl;
    return ans;
}

void calcPasc() {
    for(int i=0; i <= LIM_N; i++) {
        pasc[i][0] = pasc[i][i] = 1 ;
        for(int j = 1 ; j < i; j++) {
            pasc[i][j] = pasc[i-1][j] + pasc[i-1][j-1];
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    calcPasc();

    cin >> N  >> K;
    for(int i=0; i < N; i++) {
        cin >> cxs[i] ;
    }
    ll x, y ;
    cin >> x >> y ;
    sort(cxs, cxs+N);

    cout << calc(y) - calc(x-1) << '\n';
}
