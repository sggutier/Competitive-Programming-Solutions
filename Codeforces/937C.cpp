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
    ll k, d, t;
    ll cicApo, difo, cicLen;
    ll ans = 0;
    cin >> k >> d >> t ;
    t *= 2, k*=2, d*=2;

    cicLen = (k/d)*d;
    if(cicLen < k)
        cicLen += d;
    difo = cicLen - k;
    cicApo = k + difo / 2;

    printf("k : %lld\n", k);
    printf("d : %lld\n", d);
    printf("t : %lld\n", t);
    
    ans += (t/cicApo)*cicLen ;
    t %= cicApo;
    printf("ans : %lld\n", ans);
    printf("cicApo : %lld\n", cicApo);
    printf("cicLen : %lld\n", cicLen);
    printf("t : %lld\n", t);
    if(t > k) {
        ans += k;
        t -= k;
        ans += t*2;
    }
    else {
        ans += t;
    }

    cout << ans/2 << '.' << (ans%2==0? '0' : '5') << endl;
}
