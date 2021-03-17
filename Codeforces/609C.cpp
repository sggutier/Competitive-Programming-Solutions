#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM_N = 1e5 + 5;

int N ;
ll nums[LIM_N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    ll sm = 0 ;
    ll tgt, rem ;
    cin >> N ;
    ll minV = numeric_limits<ll>::max();
    ll maxV = numeric_limits<ll>::min();
    for(int i=0; i < N; i++) {
        cin >> nums[i];
        sm += nums[i];
        maxV = max(maxV, nums[i]);
        minV = min(minV, nums[i]);
    }
    // cout << minV << " " << maxV << endl;
    sort(nums, nums+N, greater<int>());
    rem = sm % N;
    tgt = sm / N;
    ll ans = 0 ;
    // cout << rem << " " << tgt << endl;
    for(int i=0; i < N; i++) {
        ll x = tgt + (i < rem? 1 : 0);
        ans += abs(nums[i] - x);
    }
    // cout << ans << endl;
    cout << ans / 2 << endl;
}
