#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, k, x;
    cin >> t >> k >> x;
    if(x==t) {
        cout << "YES" << endl;
        return 0;
    }
    if(x < t) {
        cout << "NO" << endl;
        return 0;
    }

    t += k;
    if( x>=t && ((x-t) % k == 0 || (x-t-1)%k == 0)) {
        cout << "YES" << endl;
        return 0;
    }
    else {
        cout << "NO" << endl;
        return 0;
    }
}
