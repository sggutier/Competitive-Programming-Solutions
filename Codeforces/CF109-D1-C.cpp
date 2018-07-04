#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;

int isLucky(int n) {
    while(n) {
        if(n%10 != 4 && n%10 != 7)
            return false;
        n /= 10;
    }
    return true;
}

ll ans = 0;
int N;
vector < pair<int,int> > adj[limN];
ll tam[limN];

void cuenta(int pos=1, int ant=-1, bool isL = true) {
    tam[pos]++;
    for(const auto &sig : adj[pos])
        if(sig.second != ant) {
            cuenta(sig.second, pos, sig.first);
            if(!sig.first)
                tam[pos] += tam[sig.second];
        }
    if(tam[pos]<2 || !isL)
        return;
    ans -= tam[pos]*(tam[pos]-1)*2*(N-tam[pos]);
    ans -= tam[pos]*(tam[pos]-1)*(tam[pos]-2);
}

int main() {
    scanf("%d", &N);
    ans = N;
    for(int i=1; i<N; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        c = isLucky(c);
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    ans = ans*(ans-1)*(ans-2);
    cuenta();
    printf("%lld\n", ans);
}
