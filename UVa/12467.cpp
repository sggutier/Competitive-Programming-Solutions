#include <bits/stdc++.h>
using namespace std;

vector <int> calcPi(const string &W) {
    int lenW = W.size();
    vector <int> pi(lenW+1);
    int posW = 0, maxR = -1;
    pi[0] = -1;
    while(posW < lenW) {
        while(maxR >= 0 && W[posW] != W[maxR]) {
            maxR = pi[maxR];
        }
        posW++, maxR++;
        pi[posW] = maxR;
    }
    return pi;
}

int maxMatch(const string &W, const string &S) {
    vector <int> pi = calcPi(W);
    int maxMatch = 0;
    int posW = 0, posS = 0;
    int lenW = W.size(), lenS = S.size();
    while(posS < lenS) {
        while(posW >= 0 && W[posW] != S[posS]) {
            posW = pi[posW];
        }
        posW++, posS++;
        maxMatch = max(maxMatch, posW);
    }
    return maxMatch;
}

void testCase() {
    string W, S;
    cin >> W;
    S = W;
    reverse(S.begin(), S.end());

    int mm = maxMatch(W, S);
    for(int i=mm-1; i >=0; i--) {
        printf("%c", W[i]);
    }
    printf("\n");
}

int main() {
    cin.sync_with_stdio(true);
    int T ;
    for(cin >> T; T; T--) {
        testCase();
    }
}
