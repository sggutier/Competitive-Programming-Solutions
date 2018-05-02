#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int N ;
int dstA[limN], dstB[limN];
vector <int> adj[limN];
bool usd[limN][limN];

void bfs(int ini, int *dst) {
    dst[ini] = 1;
    queue <int> Q;
    Q.push(ini);
    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        for(const int &sig:adj[pos]) {
            if(dst[sig]) continue;
            dst[sig] = dst[pos] + 1;
            Q.push(sig);
        }
    }
    for(int i=1; i<=N; i++)
        dst[i]--;
}

int main() {
    int E;
    int A, B;
    int ans = 0;

    scanf("%d%d%d%d", &N, &E, &A, &B);
    for(int i=0; i<E; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        usd[a][b] = usd[b][a] = true;
    }

    bfs(A, dstA);
    bfs(B, dstB);
    usd[A][B] = true;
    for(int i=1; i<=N; i++) {
        for(int j=i+1; j<=N; j++) {
            if(!usd[i][j] && 
               dstA[B] <= dstA[i] + dstB[j] +1 &&
               dstA[B] <= dstA[j] + dstB[i] +1 ) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
}
