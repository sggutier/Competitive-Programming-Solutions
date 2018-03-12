#include <bits/stdc++.h>
using namespace std;
const int limN = 200;
#define par pair<int, int>
#define f first
#define s second

int N, E;
int adj[limN][limN];
int deg[limN];

void eulPath(int pos) {
    for(int i=0; i<limN; i++) {
        if(adj[pos][i]) {
            deg[i] --;
            deg[pos] --;
            adj[pos][i] --;
            adj[i][pos] --;
            eulPath(i);
        }
    }
}

bool testCase() {
    memset(deg, 0, sizeof(deg));
    memset(adj, 0, sizeof(adj));
    for(int i=0; i<E; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        deg[a]++;
        deg[b]++;
        adj[a][b] ++;
        adj[b][a] ++;
    }
    E = -1;
    for(int i=0; i<N; i++) {
        if(!deg[i])
            continue;
        if(deg[i]%2==0) {
            E = i;
        }
        else {
            return false;
        }        
    }
    if(E==-1)
        return false;
    if(E!=-1)
        eulPath(E);
    for(int i=0; i<N; i++) {
        if(deg[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    while(scanf("%d%d", &N, &E)!=EOF)
        printf("%s\n", testCase()? "Possible" : "Not Possible");
}
