#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;
typedef pair<int, int> pii;
#define f first
#define s second

int N, E, K;
int deg[limN];
set <int> adj[limN];
int arsts[limN][2];
set <pii> trips;
int ans[limN];

void limpia() {
    // printf("limpiando\n");
    while(!trips.empty() && trips.begin()->f < K) {
        int pos = trips.begin()->s; trips.erase(trips.begin());
        // deg[pos] = 0;
        // printf("borrando %d\n", pos);
        // printf("\t vecs son ");
        for(const int sig : adj[pos]) {
            if(deg[sig] < K)
                continue;
            // printf("[%d %d] ", deg[sig], sig);
            trips.erase({deg[sig], sig});
            deg[sig] --;
            // adj[sig].erase(pos);
            trips.emplace(deg[sig], sig);
        }
        // printf("\n");
        // getchar();
        // adj[pos].clear();
    }
    // printf("limpianderino\n");
}

int main() {
    scanf("%d%d%d", &N, &E, &K);
    for(int i=0; i<E; i++) {
        for(int j=0; j<2; j++) {
            scanf("%d", &arsts[i][j]);
            deg[--arsts[i][j]] ++;
        }
        // printf(">> %d %d\n",arsts[i][0], arsts[i][1]);
        adj[arsts[i][0]].insert(arsts[i][1]);
        adj[arsts[i][1]].insert(arsts[i][0]);
    }

    for(int i=0; i<N; i++)
        trips.emplace(deg[i], i);

    limpia();

    ans[E] = trips.size();
    for(int i=E-1; i>=0; i--) {
        // for(int i=0; i<N; i++)
        //     printf("%d ", deg[i]);
        // printf("\n");
        // printf("\t en set:\n\t");
        // for(const auto &p : trips)
        //     printf("[%d %d] ", p.first, p.second);
        // printf("\n");
        if( (deg[arsts[i][0]] >= K) && (deg[arsts[i][1]] >= K) ) {
            for(int j=0; j<2; j++) {
                // printf("\t vals son %d\n", arsts[i][j]);
                adj[arsts[i][1-j]].erase(arsts[i][j]);
                trips.erase({deg[arsts[i][j]], arsts[i][j]});
                deg[arsts[i][j]] --;
                trips.emplace(deg[arsts[i][j]], arsts[i][j]);
            }
        }
        // for(int i=0; i<N; i++)
        //     printf("%d ", deg[i]);
        // printf("\n");
        // printf("\t en set:\n\t");
        // for(const auto &p : trips)
        //     printf("[%d %d] ", p.first, p.second);
        // printf("\n");
        limpia();
        ans[i] = trips.size();
        // printf("------------\n");
    }

    for(int i=1; i<=E; i++)
        printf("%d\n", ans[i]);
}
