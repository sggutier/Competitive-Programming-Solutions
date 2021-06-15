#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

int N ;
bool mat[limN][limN];
vector <int> adj[limN];
int col[limN];
bool usd[limN][4];

void brutea(int pos) {
    if(pos == N) {
        for(int i=0; i<N; i++)
            printf("%d %d\n", i+1, col[i]+1);
        exit(0);
    }
    usd[pos][0] = usd[pos][1] = usd[pos][2] = usd[pos][3] = 0;
    for(const int pv : adj[pos])
        usd[pos][col[pv]] = true;
    for(int i=0; i<4; i++)
        if(!usd[pos][i]) {
            col[pos] = i;
            brutea(pos+1);
        }
}

int main() {
    int a, b ;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        usd[i][i] = true;
    while(scanf("%d-%d", &a, &b) != EOF) {
        if(a > b)
            swap(a, b);
        a--, b--;
        if(!mat[a][b])
            adj[b].push_back(a);
        mat[a][b] = true;
    }
    // for(int i=0; i<N; i++) {
    //     printf("%d => ", i + 1);
    //     for(const int pv : adj[i])
    //         printf("%d ", pv + 1);
    //     printf("\n");
    // }
    brutea(0);
}
