#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int cols[limN];
bool usd[limN];
set <int> adj[limN];

int main() {
    int N, E ;

    scanf("%d%d", &N, &E);
    for(int i=0; i<N; i++) {
        scanf("%d", &cols[i]);
        usd[cols[i]] = true;
    }

    for(int i=0, a, b; i<E; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        if(cols[a] == cols[b]) continue;
        a = cols[a];
        b = cols[b];
        adj[a].insert(b);
        adj[b].insert(a);
    }

    pair <int, int> ans = {-1, 0};
    for(int i=0; i<limN; i++) {
        if(usd[i])
            ans = max(ans, {(int) adj[i].size(), -i});
    }

    printf("%d\n", -ans.second );
}
