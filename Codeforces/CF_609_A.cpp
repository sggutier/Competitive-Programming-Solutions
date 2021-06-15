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
    int N, K ;
    int nums[1005];
    cin >> N >> K ;
    for(int i=0; i < N; i++)
        cin >> nums[i];
    sort(nums, nums+N, greater_equal<int>());
    int ans = 0, sm = 0;
    for(; ans < N && sm < K; ans++) {
        sm += nums[ans];
    }
    printf("%d\n", ans);
}
