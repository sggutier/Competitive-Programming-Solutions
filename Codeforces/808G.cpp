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

string S, W;
int lenS, lenW;
vector <int> pi;
vector<vector<int>> dp;
vector<vector<bool>> usd;

int memo(int posW, int posS) {
    if(posS == lenS) {
        return 0;
    }
    if(usd[posW][posS]) {
        return dp[posW][posS];
    }
    usd[posW][posS] = true;
    int &maxM = dp[posW][posS];
    if(S[posS] != '?') {
        while(posW >= 0 && W[posW] != S[posS]) {
            posW = pi[posW];
        }
        posW++, posS++;
        if(posW == lenW) {
            maxM++;
            posW = pi[posW];
        }
        maxM += memo(posW, posS);
    }
    else {
        int pw2 = posW;
        pw2 = pi[pw2];
        if(pw2 >= 0) {
            maxM = memo(pw2, posS) ;
        }
        pw2 = posW + 1;
        int ans2 = 0;
        if(pw2 == lenW) {
            ans2 ++;
            pw2 = pi[pw2];
        }
        maxM = max(maxM, memo(pw2, posS + 1) + ans2);
    }
    return maxM;
}

int main() {
    cin.sync_with_stdio(true);
    cin >> S >> W;
    lenW = W.size(), lenS = S.size();
    pi = calcPi(W);
    dp.resize(lenW);
    usd.resize(lenW);
    for(int i=0; i < lenW; i++) {
        dp[i].resize(lenS);
        usd[i].resize(lenS);
    }
    cout << memo(0, 0) << endl;
}
