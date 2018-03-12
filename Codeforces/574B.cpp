#include <bits/stdc++.h>
using namespace std;
const int limN = 4005;

bool adj[limN][limN];
int deg[limN];

int main() {
    int N, E;
    int A[limN], B[limN];
    int ans = limN*3;

    scanf("%d%d", &N, &E);
    for(int i=0; i<E; i++) {
        scanf("%d%d", &A[i], &B[i]);
        adj[A[i]][B[i]] = true;
        adj[B[i]][A[i]] = true;
        deg[A[i]]++;
        deg[B[i]]++;
    }

    for(int i=0; i<E; i++) {
        int x = A[i], y = B[i];
        for(int z=1; z<=N; z++) {
            if(adj[x][z] && adj[y][z]) {
                ans = min(ans, deg[x]+deg[y]+deg[z]-6);
            }
        }
    }

    printf("%d\n", ans==limN*3? -1 : ans);
}
