#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
    int ans = -inf;
    int N ;
    cin >> N ;
    while(N--) {
        int a, b ;
        cin >> a ;
        b = a>0? sqrt(a) : 0;
        if( b*b != a )
            ans = max(ans, a);
    }
    cout << ans << endl;
}
