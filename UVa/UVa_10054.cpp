#include <bits/stdc++.h>
using namespace std;
const int limN = 51;
#define par pair<int, int>
#define f first
#define s second

int N;
int adj[limN][limN];
int deg[limN];
list <par> ans;

void eulPath(int pos, list <par>::iterator it=ans.begin()) {
    for(int i=0; i<limN; i++) {
        if(adj[pos][i]) {
            deg[i] --;
            deg[pos] --;
            adj[pos][i] --;
            adj[i][pos] --;
            eulPath(i, ans.insert(it, par(i, pos)));
        }
    }
}

void testCase() {
    ans.clear();
    memset(deg, 0, sizeof(deg));
    memset(adj, 0, sizeof(adj));
    int E;
    bool works = true;
    scanf("%d", &E);
    for(int i=0; i<E; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        deg[a]++;
        //if(a!=b)
        deg[b]++;
        adj[a][b] ++;
        adj[b][a] ++;
    }
    // for(int i=0; i<10; i++) {
    //     printf("%d (%d) =>", i+1, deg[i]);
    //     for(int j=0; j<10; j++) {
    //         printf("%d ", adj[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=0; i<limN; i++) {
        if(!deg[i])
            continue;
        if(deg[i]%2==0) {
            E = i;
        }
        else {
            works = false;
            break;
        }        
    }
    if(!works) {
        printf("some beads may be lost\n");
        return;
    }
    eulPath(E);
    for(const auto &p:ans)
        printf("%d %d\n", p.first+1, p.second+1);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        printf("Case #%d\n", i+1);
        testCase();
    }
}
