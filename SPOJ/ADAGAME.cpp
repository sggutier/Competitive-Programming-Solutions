#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4;

vector <int> adj[limN + 5];

void getNbrs(int n) {
    for(int p=1; p<limN; p*=10) {
        int d = ((n/p) % 10) * p;
        int w = (d + p) % (p*10);
        adj[n].push_back(n-d+w);
    }
}

int iniNum;

bool adaG(const int pos, const int rem) ;
bool vinG(const int pos, const int rem) ;

bool usd[limN + 5][105];
bool dp[limN + 5][105];

bool adaG(const int pos, const int rem) {
    if(rem <= 0)
        return pos > iniNum;
    if(usd[pos][rem])
        return dp[pos][rem];
    usd[pos][rem] = true;
    dp[pos][rem] = false;
    for(const int sig : adj[pos])
        if(!vinG(sig, rem-1))
            return dp[pos][rem] = true;
    return false;
}

bool vinG(const int pos, const int rem) {
    if(rem <= 0)
        return pos <= iniNum;
    if(usd[pos][rem])
        return dp[pos][rem];
    usd[pos][rem] = true;
    dp[pos][rem] = false;
    for(const int sig : adj[pos])
        if(!adaG(sig, rem-1))
            return dp[pos][rem] = true;
    return false;
}

int main() {
    for(int i=0; i<limN; i++)
        getNbrs(i);
    int tc;
    int n, r;
    for(scanf("%d", &tc); tc; tc--) {
        scanf("%d%d", &n, &r);
        iniNum = n;
        memset(usd, 0, sizeof(usd));
        printf("%s\n", adaG(n, r)? "Ada" : "Vinit");
    }
}
