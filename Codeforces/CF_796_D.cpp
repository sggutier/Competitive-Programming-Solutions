#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limN = 3e5 + 5;

bool util[limN];
list <par> adj[limN];
int prevo[limN];

int main() {
    int N, stC, D ;
    queue <int> Q;

    scanf("%d%d%d", &N, &stC, &D);
    for(int i=0; i<stC; i++) {
        int a ;
        scanf("%d", &a);
        Q.push(a);
        prevo[a] = N;
    }
    for(int i=1; i<N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        adj[a].push_back(par(b, i));
        adj[b].push_back(par(a, i));
    }

    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        util[prevo[pos]] = true;
        for(const par &edg:adj[pos]) {
            int sig = edg.f, e = edg.s  ;
            if(!prevo[sig]) {
                prevo[sig] = e;
                Q.push(sig);
            }
        }
    }

    stC = 0;
    for(int i=1; i<N; i++)
        if(!util[i])
            stC++;
    printf("%d\n", stC);
    for(int i=1; i<N; i++)
        if(!util[i])
            printf("%d ", i);
    printf("\n");
}
