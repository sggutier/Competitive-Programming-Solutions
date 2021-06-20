#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> par;
const int limN = 4005;
const int inf = 1e9;
#define f first
#define s second

int N;
vector <par> adj[limN][26];

int dijkstra(int ini, int fin) {
    vector <int> minP;
    minP.assign(N*26, inf);
    priority_queue <par> Q;

    for(int i=0; i<26; i++) {
        Q.push(par(0, ini*26 + i));
        minP[ini*26 + i] = 0;
    }
    while(!Q.empty()) {
        int pos = Q.top().s, dst = -Q.top().f; Q.pop();
        //printf("%d %d\n", pos, dst);
        if(minP[pos] > dst)
            continue;
        int let = pos%26, num = pos/26;
        if(num==fin)
            return dst;
        for(int b=0; b<26; b++) {
            if(b==let)
                continue;
            for(const par &e:adj[num][let]) {
                int nov = e.f + dst;
                int sig = e.s*26 + b;
                //printf("\t%d %d => %d\n", sig.s, nov, minP[sig.s]);
                if(nov < minP[sig]) {
                    minP[sig] = nov;
                    Q.push(par(-nov, sig));
                }
            }
        }
    }
    
    return inf;
}

int getID(string str, map <string, int> &ids) {
    if(ids.count(str)==0)
        ids[str] = ids.size();
    return ids[str];
}

void testCase() {
    map <string, int> ids;
    int ini, fin;
    char str[500];

    scanf("%s", str);
    ini = getID(str, ids);
    scanf("%s", str);
    fin = getID(str, ids);

    for(int i=2*N; i>=0; i--) {
        for(int b=0; b<26; b++)
            adj[i][b].clear();
    }

    for(int i=0; i<N; i++) {
        scanf("%s", str);
        int a = getID(str, ids);
        scanf("%s", str);
        int b = getID(str, ids);
        int c;
        scanf("%s", str);
        c = strlen(str);
        adj[a][str[0]-'a'].push_back(par(c, b));
        adj[b][str[0]-'a'].push_back(par(c, a));
    }
    N = ids.size()+1;

    int ans = dijkstra(ini, fin);
    if(ans==inf)
        printf("impossivel\n");
    else
        printf("%d\n", ans);
}

int main() {
    while(scanf("%d", &N)!=EOF && N)
        testCase();
}
