#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll potMod(ll k) {
    if(k==0) {
        return 1;
    }
    ll mit = potMod(k/2);
    return ( mit*mit*(k%2? 2 : 1) ) % mod;
}

int main() {
    ll x, k;
    cin >> x >> k;
    if(x==0) {
        cout << 0 << endl;
        return 0;
    }
    ll xmen = (x-1) % mod, xnorm = x % mod;
    ll pot2 = potMod(k);
    ll a = (pot2 * xmen + 1) % mod;
    ll b = (pot2 * xnorm) % mod;
    ll ans = (a + b) % mod;
    cout << ans << endl;
}
