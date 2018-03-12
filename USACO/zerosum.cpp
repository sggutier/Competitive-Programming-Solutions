/*
ID: me60
LANG: C++11
TASK: zerosum
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(string &S, int pos, int sum, int ant) {
    // cout << S << " -> " << sum << " " << ant << endl;
    if(pos>(int) S.size()) {
        if(sum==0)
            printf("%s\n", S.c_str());
        return;
    }
    S[pos-1] = ' ';
    int k = (abs(ant)*10 + (S[pos]-'0')) * (ant<0? -1 : 1);
    dfs(S, pos+2, sum-ant + k, k);
    S[pos-1] = '+';
    dfs(S, pos+2, sum+(S[pos]-'0'), S[pos]-'0');
    S[pos-1] = '-';
    dfs(S, pos+2, sum-(S[pos]-'0'), -(S[pos]-'0'));
    // S[pos-1] = '#';
}

int main() {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    
    string ans;
    int n;

    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        if(i>1)
            ans += (char) '#';
        ans += (char) ('0' + i);
    }

    dfs(ans, 2, 1, 1);

    return 0;
}
