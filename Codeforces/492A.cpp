#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, s = 1 ;
    long long ans = 0;
    cin >> n ;
    for(int i=1; s<=n; i++) {
        ans = i;
        s += ((i+1)*(i+2)) / 2;
    }
    cout << ans << endl;
}
