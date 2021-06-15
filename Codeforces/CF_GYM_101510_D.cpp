#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int limN = 1e5 + 5;

struct Mod {
        ll x ;
        Mod(ll x = 0) : x(x) {}
        Mod operator+(Mod otr) { return (this->x + otr.x) % mod; }
        Mod operator-(Mod otr) { return (this->x + mod - otr.x) % mod; }
        Mod operator*(Mod otr) { return (this->x * otr.x) % mod;}
};

bool usd[100][limN];
Mod memo[100][limN];

Mod f(int bas, int rem) {
        if(rem == 0) {
                printf("%d %d => %lld\n", bas, rem, 1);
                return 1;
        }
        if(usd[bas][rem]) {
                return memo[bas][rem];
        }
        Mod& ans = memo[bas][rem];
        for(int i=min(bas-1, rem); i>=1; i--) {
                ans = ans  + Mod(bas-i)*f(i, rem -i);
        }
        printf("%d %d => %lld\n", bas, rem, ans.x);
        return ans;
}

int main() {
        int R, C;
        scanf("%d%d", &R, &C);
        Mod ans = 0;
        for(int i=1; i<=C; i++) {
                ans = ans + f(i, C-i);
        }
        printf("%lld\n", ans.x);
}
