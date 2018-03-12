#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n ;
    ll a ;

    cin >> n ;
    while(n--) {
        cin >> a ;
        ll ans = (a*(a+1))/2;
        for(int b=0; (1LL<<b) <= a; b++)
            ans -= 2*(1LL<<b);
        cout << ans << endl;
    }
}
