#include <bits/stdc++.h>
using namespace std;
const int limN = 30;

vector <int> adj[limN];
bool usd[limN];

void dfs(int pos) {
    if(usd[pos])
        return;
    usd[pos] = true;
    for(const int &sig:adj[pos])
        dfs(sig);
}

int testCase(int prev=-1) {
    int N ;
    char S[5];

    if(prev==-1) {
        scanf("%s", S);
        N = S[0]-'A'+1;
    }
    else
        N = prev;

    for(int i=0; i<N; i++)
        adj[i].clear();
    memset(usd, 0, sizeof(usd));

    while(scanf("%s", S)!=EOF && S[1]) {
        int a = S[0]-'A', b = S[1] - 'A';
        // printf("%d %d\n", a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    for(int i=0; i<N; i++) {
        if(usd[i])
            continue;
        ans ++;
        dfs(i);
    }
    printf("%d\n", ans);

    return S[0]-'A'+1;
}

int main() {
    int tc ;
    scanf("%d", &tc);

    for(int i=0, ant=-1; i<tc; i++) {
        if(i)
            printf("\n");
        ant = testCase(ant);
    }
}
