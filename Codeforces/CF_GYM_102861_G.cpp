#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int N ;
    int sm = 100 ;
    int ans = 100;

    cin >> N ;
    for(int i=0, x; i < N; i++) {
        cin >> x ;
        sm += x;
        ans = max(ans, sm);
    }

    cout << ans << endl;
}
