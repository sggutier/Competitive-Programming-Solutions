#include <bits/stdc++.h>
using namespace std;

vector <int> calcZ(const string &W, const string &_S) {
    string S = W + "\n" + _S;
    int lenS = S.length();
    vector <int> z(lenS);
    int x=0, y=0 ;
    for(int i=1; i < lenS; i++) {
        z[i] = max(0, min(z[i-x], y - i + 1));
        while(S[z[i]] == S[i + z[i]]) {
            x = i ;
            y = i + z[i];
            z[i] ++;
        }
    }
    return z;
}

vector <int> getMatches(const string &W, const string &S) {
    auto z = calcZ(W, S);
    int lenW = W.size(), lenWS = W.size() + 1 + S.size();
    vector <int> matches ;
    for(int i=lenW+1; i < lenWS; i++) {
        if(z[i] == lenW) {
            matches.push_back(i - (lenW + 1));
        }
    }
    return matches;
}

void testCase(const string &W, const string &S) {
    vector <int> matches = getMatches(W, S);
    bool fst = true;
    for(const int m : matches) {
        if(!fst) {
            printf(" ");
        }
        printf("%d", m);
        fst = false;
    }
    printf("\n");
}

int main() {
    ios::sync_with_stdio(true);
    string W, S;
    while(getline(cin, W)) {
        getline(cin, S);
        testCase(W, S);
    }
}
