#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k, a, b;
    long long ans = 0;
    cin >> n >> k >> a >> b ;
    if(k==1) {
        ans = (n-1)*a;
        n = 0;
    }
    while(n > 1) {
        int sig = max(1LL, n/k);
        long long mc = (n-sig)*a;
        if(n >= k)
            mc = min(mc, (n%k)*a + b);
        // cout << n << " " << mc << " " << sig << endl;
        ans += mc;
        n = sig;
    }
    cout << ans << endl;
}
