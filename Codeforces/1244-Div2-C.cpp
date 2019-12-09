#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, p, w, d;
    ll x=0, y=0, z=0;

    cin >> n >> p >> w >> d ;

    while((y*d) % w != p % w) {
        y++;
        if((y*d) % w == 0) {
            cout << -1 << endl;
            return 0 ;
        }
    }

    if(y*d > p) {
        cout << -1 << endl;
        return 0 ;
    }

    x = (p - y * d)/w ;
    if(x + y > n) {
        cout << -1 << endl;
        return 0 ;
    }

    z = n - (x + y);

    printf("%lld %lld %lld\n", x, y, z);
}
