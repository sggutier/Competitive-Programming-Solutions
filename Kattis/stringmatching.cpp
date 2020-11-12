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

vector <int> getMatches(const string &W, const string &S) {
    vector <int> pi = calcPi(W);
    vector <int> matches ;
    int posW = 0, posS = 0;
    int lenW = W.size(), lenS = S.size();
    while(posS < lenS) {
        while(posW >= 0 && W[posW] != S[posS]) {
            posW = pi[posW];
        }
        posW++, posS++;
        if(posW == lenW) {
            matches.push_back(posS - lenW);
            posW = pi[posW];
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
