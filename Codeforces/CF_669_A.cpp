#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans=0;

    cin >> n ;
    ans = 2*(n/3) + (n%3? 1 : 0);
    cout << ans << endl;
}
