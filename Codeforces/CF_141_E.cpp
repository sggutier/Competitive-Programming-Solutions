#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5 ;

struct Nodo {
    Nodo *par = NULL ;
    Nodo* root() {
        if(this->par == NULL)
            return this;
        return par = par->root();
    }
    bool join(Nodo* y) {
        Nodo* x = this->root();
        y = y->root();
        if(x == y)
            return false;
        y->par = x;
        return true;
    }
};

Nodo *nods[LIM_N], *kods[LIM_N];
int tipos[LIM_N];
int xs[LIM_N], ys[LIM_N];
bool usd[LIM_N];
vector <pair<int,int>> adj[LIM_N];
int T = 0 ;
int lastS[LIM_N];

bool dfs(const int pos, const int pvE = -1) {
    if(lastS[pos] == T) {
        return true;
    }
    lastS[pos] = T ;
    for(const auto &e : adj[pos]) {
        if(e.first == pvE || !usd[e.first]) continue;
        bool rv = dfs(e.second, e.first);
        if(rv) {
            if(tipos[e.first] == 0) {
                usd[e.first] = false;
                return false;
            }
            return true;
        }
    }
    return false;
}

int main() {
    int N, E ;
    char tmp[5];

    scanf("%d%d", &N, &E);
    for(int i=0; i < E; i++) {
        scanf("%d%d%s", &xs[i], &ys[i], tmp);
        tipos[i] = tmp[0] == 'S';
        xs[i] --;
        ys[i] --;
    }
    for(int i=0; i < N; i++) {
        nods[i] = new Nodo();
        kods[i] = new Nodo();
    }

    if(N % 2 == 0) {
        printf("-1\n");
        return 0 ;
    }

    for(int i=0; i < E; i++) {
        if(tipos[i] != 0 || xs[i] == ys[i]) continue;
        usd[i] = nods[xs[i]]->join(nods[ys[i]]);
        if(usd[i]) {
            adj[xs[i]].emplace_back(i, ys[i]);
            adj[ys[i]].emplace_back(i, xs[i]);
            // printf("%d %d\n", xs[i] + 1, ys[i] + 1);
        }
    }

    int cnt = -1 ;
    for(int i=0; i < N; i++)
        if(nods[i]->par == NULL)
            cnt ++;

    int mit = (N-1) / 2;
    if(cnt > mit) {
        // printf("B\n");
        printf("-1\n");
        return 0 ;
    }

    for(int i=0; i < N; i++) {
        kods[i] = new Nodo();
    }

    // printf("rem = %d\n", cnt);
    cnt = mit;
    for(int i=0; i < E && cnt; i++) {
        if(usd[i] || tipos[i] != 1 || xs[i] == ys[i]) continue;
        usd[i] = nods[xs[i]]->join(nods[ys[i]]);
        if(usd[i]) {
            kods[xs[i]]->join(kods[ys[i]]);
            adj[xs[i]].emplace_back(i, ys[i]);
            adj[ys[i]].emplace_back(i, xs[i]);
            cnt -- ;
            // printf("%d %d\n", xs[i] + 1, ys[i] + 1);
        }
    }

    for(int i=0; i < E && cnt; i++) {
        if(usd[i] || tipos[i] != 1 || xs[i] == ys[i]) continue;
        usd[i] = kods[xs[i]]->join(kods[ys[i]]);
        if(usd[i]) {
            adj[xs[i]].emplace_back(i, ys[i]);
            adj[ys[i]].emplace_back(i, xs[i]);
            T ++ ;
            dfs(xs[i]);
            cnt -- ;
        }
    }

    if(cnt) {
        // printf("C\n");
        printf("-1\n");
        return 0 ;
    }

    printf("%d\n", (N-1) );
    for(int i=0; i < E; i++) {
        if(usd[i])
            printf("%d ", i+1);
    }
    printf("\n");
}
