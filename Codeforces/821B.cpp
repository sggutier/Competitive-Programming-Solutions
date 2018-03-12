#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sumo(ll a) {
    return (a*(a+1))/2;
}

int main() {
    ll m, b ;
    ll ans = 0 ;
    cin >> m >> b ;
    for(ll x=m*b; x>=0; x--) {
        ll y = -x/m + b - (x%m? 1 : 0);
        ans = max(ans, sumo(y)*(x+1) + sumo(x)*(y+1));
    }
    cout << ans << endl;
}
