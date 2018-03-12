#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, u=1e9 + 5;
    int ans = 1;

    cin >> N ;
    for(int i=0, c=0; i<N; i++) {
        int a ;
        cin >> a;
        if(a < u)
            c = 0;
        u = a;
        ans = max(ans, ++c);
    }

    cout << ans << endl;
}
