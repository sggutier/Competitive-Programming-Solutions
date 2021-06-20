#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dp[1000][1000];
bool usd[1000][1000];

int gana(ll a, ll b) {
    if(b < a) swap(a, b);
    if(a == 0) return 0 ;
    if(b % a == 0) return 1 ;
    if(b >= 2*a) return 1 ;
    ll g = __gcd(a, b);
    a /= g ;
    b /= g ;
    return 1 - gana(a, b-a);
}

int main() {
    ll a, b ;
    while(scanf("%lld%lld", &a, &b) != EOF && (a || b)) {
        printf("%s wins\n", gana(a, b)? "Stan" : "Ollie");
    }
}
