#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

vector <int> adj[limN];
int cols[limN];

int dfs(int pos=1, int ant=0) {
    int ans = 1 + adj[pos].size();
    int w = 1;
    for(const int &sig:adj[pos]) {
        if(sig!=ant) {
            while(w==cols[pos] || w==cols[ant])
                w++;
            cols[sig] = w++;
        }
    }
    for(const int &sig:adj[pos])
        if(sig!=ant)
            ans = max(ans, dfs(sig, pos));
    return ans;
}

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=1; i<N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cols[1] = 1;
    printf("%d\n", dfs());
    for(int i=1; i<=N; i++)
        printf("%d ", cols[i]);
    printf("\n");
}
