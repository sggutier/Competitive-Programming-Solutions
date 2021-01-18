#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 1e4 + 5;

int nums[LIM_N];

void testCase(int n, int m) {
    int tot = 0 ;
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++)
            scanf("%d", &nums[i]);
        tot += nums[i];
    }
    for(int i=0; i < n; i++) {
        int g = __gcd(nums[i], tot);
        printf("%d / %d\n", nums[i] / g, tot / g);
    }
}

int main() {
    int n, m ;
    while(scanf("%d%d", &n, &m) != EOF && (n || m)) {
        testCase(n, m);
    }
}
