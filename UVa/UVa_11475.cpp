#include <bits/stdc++.h>
using namespace std;

vector <int> funcionZ(const string &S) {
    int lenS = S.length();
    vector <int> z(lenS);
    int x = 0, y = 0 ;
    for(int i = 1 ; i < lenS; i++) {
        z[i] = max(0, min(z[i-x], y-i+1));
        while(i + z[i] < lenS && S[z[i]] == S[i + z[i]]) {
            x = i;
            y = i + z[i];
            z[i] ++;
        }
    }
    return z ;
}

void testCase(const string &S) {
    int N = S.size();
    auto revS = S;
    reverse(revS.begin(), revS.end());
    auto conc = revS + "#" + S;
    auto z = funcionZ(conc);
    int maxP = 0 ;

    for(int i=0; i < N; i++) {
        if(i + z[i + N + 1] == N) {
            maxP = max(maxP, z[i+N+1]);
        }
    }

    cout << S ;
    for(int i=N-maxP-1; i >=0; i--) {
        cout << S[i] ;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio();
    string S ;
    while(cin >> S) {
        testCase(S);
    }
}
