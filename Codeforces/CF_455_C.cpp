#include <bits/stdc++.h>
using namespace std;
const int limN = 3e5 + 5;
typedef pair<int,int> pii;
#define f first
#define s second

vector <int> adj[limN];
int padr[limN];
int maxLA[limN], maxLB[limN], maxT[limN];

pii dfs(int pos, int p, int prev = -1) {
    if(padr[pos])
        return {0, 0};
    int &mla = maxLA[pos], &mlb = maxLB[pos];
    int &ans = maxT[pos];
    padr[pos] = p;
    // printf("papr %d %d, %d\n", pos, p, prev);
    // for(const int sig : adj[pos]) {
    //     if(sig == prev) continue;
    //     printf("\t llama a %d\n", sig);
    // }
    for(const int sig : adj[pos]) {
        if(sig == prev) continue;
        pii w = dfs(sig, p, pos);
        ans = max(ans, w.f);
        mlb = max(mlb, w.s + 1);
        if(mla < mlb)
            swap(mla, mlb);
    }
    ans = max(ans, mla + mlb);
    if(pos == p) {
        mla = ceil(ans/2.0);
        // printf("%d | %d => %d %d\n", pos, p, ans, mla);
    }
    return {ans, mla};
}

int rt(int pos) {
    while(padr[pos] != pos)
        pos = padr[pos];
    return pos;
}

int main() {
    int N, E, Q;
    scanf("%d%d%d", &N, &E, &Q);
    for(int i=0, a, b; i<E; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=N; i++)
        dfs(i, i);
    while(Q--) {
        int t;
        scanf("%d", &t);
        if(t==2) {
            int a, b ;
            scanf("%d%d", &a, &b);
            // printf("peticion de union %d %d\n", a, b);
            a = rt(a);
            b = rt(b);
            if(a==b) continue;
            // printf("uniendo a %d con %d\n", a, b);
            int mx = max(maxT[a], maxT[b]);
            int cstA = max(mx, maxLA[a] + maxLA[b] + 1);
            int cstB = max(mx, maxLA[a] + maxLA[b] + 1);
            // printf("\tcsts son %d %d\n", cstA, cstB);
            if(cstA > cstB || (cstA == cstB && maxLA[a] < maxLA[b]))
                swap(a, b);
            // printf("\t%d ahora es padre de %d\n", a, b);
            padr[b] = a;
            maxT[a] = max(mx, maxLA[a] + maxLA[b] + 1);
            maxLA[a] = max(maxLA[a], maxLA[b] +1);
        }
        else if(t==1) {
            int p ;
            scanf("%d", &p);
            p = rt(p);
            printf("%d\n", maxT[p]);
        }
    }
}
