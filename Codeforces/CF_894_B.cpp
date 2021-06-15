#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 20;
const int LIM_B = 1 << LIM_N;

ll dp[LIM_N][LIM_B];
bool usd[LIM_N][LIM_B];

int R, C, p ;
int numBits[LIM_B] ;

ll memo(int r, int msk) {
    if(usd[r][msk])
        return dp[r][msk];
    usd[r][msk] = true;
    ll &ans = dp[r][msk];
    if(r == 0) {
        return ans = msk == ((1 << C) -1)*p ;
    }
    for(int i=(1 << C)-1; i >=0; i--) {
        if(numBits[msk ^ i] % 2 == p)
            ans += memo(r-1, msk ^ i);
    }
    return ans ;
}

int main() {
    for(int msk=LIM_B-1; msk >= 0; msk--) {
        int &cnt = numBits[msk] ;
        for(int i=0; i < LIM_N; i++)
            if((1 << i) & msk)
                cnt ++;
    }
    cin >> R >> C >> p;
    printf("%lld\n", memo(R, 0));
}
