#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5;

int sig[limN];
bool usd[limN];

int dfs(int pos) {
    if(usd[pos]) return 0;
    usd[pos] = true;
    return dfs(sig[pos])+1;
}

int main() {
    vector <int> cics;
    int N ;

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &sig[i]);
    }

    for(int i=1; i<=N; i++) {
        if(usd[i]) continue;
        cics.push_back(dfs(i));
    }
    sort(cics.begin(), cics.end());

    if(cics.size() > 1) {
        int n = cics.size();
        cics[n-2] += cics[n-1];
        cics.resize(n-1);
    }

    long long ans = 0;
    for(const int &a:cics) {
        long long t = a;
        ans += t*t;
    }

    printf("%lld\n", ans);
}
