#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    long long a=1LL, b=2LL;
    int ans = 0;

    cin >> n;
    while(b<=n) {
        long long c = a+b;
        a = b;
        b = c;
        ans ++;
    }

    cout << ans << endl;
    
    return 0;
}
