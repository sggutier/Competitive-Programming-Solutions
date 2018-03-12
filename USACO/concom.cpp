/*
ID: me60
LANG: C++11
TASK: concom
*/
#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define f first
#define s second
const int limN = 1e2 + 5;

list<par> adj[limN];

void bfs(int posOrg) {
    int cont[limN];
    queue <int> Q ;
    set <int> ans ;
    memset(cont, 0, sizeof(cont));
    cont[posOrg] = 100;
    Q.push(posOrg);

    while(!Q.empty()) {
        int pos = Q.front();  Q.pop();
        ans.insert(pos);
        for(auto &e:adj[pos]) {
            if(cont[e.f]<50 && cont[e.f] + e.s >= 50)
                Q.push(e.f);
            cont[e.f] += e.s;            
        }
    }

    for(auto &n:ans) {
        if(n==posOrg)
            continue;
        printf("%d %d\n", posOrg+1, n+1);
    }
}

int main() {
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    
    int edjCnt ;

    scanf("%d", &edjCnt);
    for(int i=0; i<edjCnt; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a].push_back(par(b, c));
        // adj[b].push_back(par(a, c));
    }

    for(int i=0; i<limN; i++)
        bfs(i);
    
    return 0;
}
