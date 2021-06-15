#include <bits/stdc++.h>
using namespace std;

int main() {
    string s ;
    int ans = 0, pos = 0;
    cin >> s ;
    for(char &c : s) {
        int k = c-'a';
        ans += min(abs(pos-k), 26 - abs(pos-k));
        pos = k;
    }
    cout << ans << endl;
}
