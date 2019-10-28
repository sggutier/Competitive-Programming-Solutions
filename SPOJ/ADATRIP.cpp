#include <cstdio>
#include <set>
#include <vector>
#include <list>
#include <ctype.h>
using namespace std;
const int limN = 5e5 +5;
const int limL = 11;
const int limD = limN*limL + 5;
const int inf = 1e9;

int N ;
// vector <int> adj[limN][limL];
list <int> adj[limN][limL];
// set <int> adj[limN][limL];

bool usd[limN];
pair<int,int> pans[limN];

int minDst[limN];
vector <int> nodesAtDst[limD];
// list <int> nodesAtDst[limD];
// set <int> nodesAtDst[limD];

void dijkstra(const int ini) {
    if(usd[ini]) {
        printf("%d %d\n", pans[ini].first, pans[ini].second);
        return;
    }
    usd[ini] = true;
    for(int i=0; i<N; i++) {
        minDst[i] = inf;
    }
    // nodesAtDst[0].insert(ini);
    nodesAtDst[0].push_back(ini);
    minDst[ini] = 0;
    // printf("ini = %d\n", ini);
    int ansP = 0;
    int ansV = 1;
    int maxD = 0;
    for(int D = 0; D<=maxD; D++) {
        bool fst = true;
        for(const int &pos : nodesAtDst[D]) {
            if(minDst[pos] < D)
                continue;
            if(fst) {
                fst = false;
                ansP = D;
                ansV = 0;
            }
            ansV ++;
            for(int s=0; s<limL; s++) {
                for(const int &sig : adj[pos][s]) {
                    if(D + s < minDst[sig]) {
                        // if(minDst[sig] != inf) {
                        //     nodesAtDst[minDst[sig]].erase(sig);
                        // }
                        minDst[sig] = D + s;
                        maxD = max(maxD, D+s);
                        // nodesAtDst[D+s].insert(sig);
                        nodesAtDst[D+s].push_back(sig);
                    }
                }
            }
        }
        nodesAtDst[D].clear();
    }
    pans[ini] = {ansP, ansV};
    printf("%d %d\n", ansP, ansV);
}

void limpia(const int &pos) {
    set <int> usd;
    for(int d=0; d<limL; d++) {
        auto it = adj[pos][d].begin();
        while(it != adj[pos][d].end()) {
            if(usd.count(*it))
                it = adj[pos][d].erase(it) ;
            else {
                usd.insert(*it);
                it++;
            }
        }
    }
}

int getInt() {
    static int ans ;
    static int c;
    while( !isdigit((c = getchar())) );
    ans = c-'0';
    while( isdigit((c = getchar())) ) {
        ans = ans*10 + c-'0';
    }
    return ans;
}

int main() {
    int E, Q ;

    // scanf("%d%d%d", &N, &E, &Q);
    N = getInt();
    E = getInt();
    Q = getInt();
    for(int i=0, a, b, c; i<E; i++) {
        // scanf("%d%d%d", &a, &b, &c);
        a = getInt();
        b = getInt();
        c = getInt();
        if(a == b) continue;
        adj[a][c].push_back(b);
        adj[b][c].push_back(a);
        // adj[a][c].insert(b);
        // adj[b][c].insert(a);
    }

    // for(int i=0; i<N; i++)
    //     limpia(i);

    for(int i=0, ini; i<Q; i++) {
        ini = getInt();
        dijkstra(ini);
    }
}
