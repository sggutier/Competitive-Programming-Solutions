#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, rem;
    int t = 0;
    int ans = 0;
    
    cin >> n >> rem;
    rem = 240-rem;

    while(n--) {
        t += 5;
        rem -= t;
        if(rem < 0)
            break;
        ans++;
    }

    cout << ans << endl;
}
