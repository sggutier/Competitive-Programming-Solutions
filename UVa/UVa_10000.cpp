#include <bits/stdc++.h>
using namespace std;
const int limN = 1e3 + 5;
typedef pair<int,int> par;
#define f first
#define s second

int N;
list <int> adj[limN];
par ans[limN];
bool usd[limN];

par maxD(int pos) {
    if(usd[pos])
        return ans[pos];
    usd[pos] = true;
    ans[pos] = par(0, -pos);
    for(const int &sig:adj[pos]) {
        par tmp = maxD(sig);
        tmp.f ++;
        ans[pos] = max(ans[pos], tmp);
    }
    return ans[pos];
}

void testCase() {
    for(int i=0; i<=N; i++) {
        adj[i].clear();
    }
    memset(usd, 0, sizeof(usd));
    int s;
    scanf("%d", &s);
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        //printf("%d => %d\n", a, b);
        adj[a].push_back(b);
    }
    par ans = maxD(s);
    printf("The longest path from %d has length %d, finishing at %d.\n", s, ans.f, -ans.s);
}

int main() {
    int tc = 0;
    while(scanf("%d", &N)!=EOF && N) {
        printf("Case %d: ", ++tc);
        testCase();
        printf("\n");
    }
}
