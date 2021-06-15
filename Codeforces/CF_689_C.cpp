#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;

LL ways(LL n) {
    LL ans = 0;
    for(LL k=2; k*k*k<=n; k++)
        ans += n/(k*k*k);
    return ans;
}

int main() {
    ll m ;
    cin >> m ;
    ll ini=0, fin=(1LL<<60);
    while(ini<fin) {
        ll piv = (ini+fin)/2;
        if(ways(piv) < m)
            ini = piv+1;
        else
            fin = piv;
    }
    if(ways(ini) != m)
        cout << -1 << endl;
    else
        cout << ini << endl;
}
