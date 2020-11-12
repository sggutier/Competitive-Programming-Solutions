#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1005;

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

void getMatchesPerRow(const string &W, const string &S, const vector<int> &pi, vector <int> &matches) {
    int posW = 0, posS = 0;
    int lenW = W.size(), lenS = S.size();
    while(posS < lenS) {
        while(posW >= 0 && W[posW] != S[posS]) {
            posW = pi[posW];
        }
        posW++, posS++;
        if(posW == lenW) {
            matches[posS-1] ++;
            posW = pi[posW];
        }
    }
}

void getMatches(const string &W, const vector <string> &S, const int offs, vector<vector <int>> &matches) {
    auto pi = calcPi(W);
    int R_S = S.size();
    for(int i=offs; i < R_S; i++) {
        getMatchesPerRow(W, S[i], pi, matches[i-offs]);
    }
}

void testCase() {
    int R_S, C_S, R_W, C_W;
    vector <string> W, S;
    char tmp[LIM_N];
    scanf("%d%d", &R_S, &C_S);
    S.resize(R_S);
    for(int i=0; i < R_S; i++) {
        scanf("%s", tmp);
        S[i] = tmp;
    }
    scanf("%d%d", &R_W, &C_W);
    W.resize(R_W);
    for(int i=0; i < R_W; i++) {
        scanf("%s", tmp);
        W[i] = tmp;
    }

    vector<vector <int>> matches(R_S);
    for(int i = 0; i < R_S; i++) {
        matches[i].resize(C_S);
    }
    for(int i=0; i < R_W; i++) {
        getMatches(W[i], S, i, matches);
    }

    int ans = 0;
    for(int i=0; i < R_S; i++) {
        for(int j=0; j < C_S; j++) {
            if(matches[i][j] == R_W) {
                ans ++;
            }
        }
    }

    printf("%d\n", ans);
}

int main() {
    int T ;
    for(scanf("%d", &T); T; T--) {
        testCase();
    }
}
