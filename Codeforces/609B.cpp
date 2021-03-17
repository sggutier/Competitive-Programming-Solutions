#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

inline ll gauss(const ll n) {
    return (n*(n+1)) >> 1;
}

ll reps[11];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int N, K;
    ll ans = 0 ;
    cin >> N >> K ;
    for(int i=0; i < N; i++) {
        int a ;
        cin >> a ;
        reps[a] ++;
    }
    ans = gauss(N-1);
    for(int i=1; i <= K; i++)
        if(reps[i])
            ans -= gauss(reps[i]-1);
    cout << ans << endl;
}
