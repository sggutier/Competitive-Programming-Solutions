#include <bits/stdc++.h>
using namespace std;

void testCase(int n) {
    string S;
    cin >> S;
    map <string, int> cnt;
    int ans = 0;

    for(int i=S.size(); i>=n; i--)
        ans = max(ans, ++cnt[S.substr(i-n, n)]);

    for(const auto &c:cnt) {
        if(c.second==ans) {
            cout << c.first << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int n;

    while(cin>>n) {
        testCase(n);
    }
}
