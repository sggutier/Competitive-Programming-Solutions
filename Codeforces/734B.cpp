#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    int ans = 0;
    cin >> b >> a >> c >> d;
    c = min(b, min(c, d));
    ans += c*256;
    b -= c;
    ans += min(a,b)*32;
    cout << ans << endl;
}
