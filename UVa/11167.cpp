#include <bits/stdc++.h>
using namespace std;
const int limRng = 5e4 + 5;
const int MAX_V = 305;
const int INF = 1e9;

int res[MAX_V][MAX_V], f, s, t;
vector <int> p;
vector <int> AdjList[MAX_V];

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
    //printf("%d ", v);
    if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
        res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}

// NOTA: ESTE CODIGO ES DEL LIBRO DE STEVE Y FELIX HALIM
int edmond_karps(int _s, int _t) {
    s = _s;
    t = _t;
    int mf = 0;
    while (1) {                     // now a true O(VE^2) Edmonds Karp's algorithm
        f = 0;
        bitset<MAX_V> vis; vis[s] = true;            // we change vi dist to bitset!
        queue<int> q; q.push(s);
        p.assign(MAX_V, -1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int j = 0; j < (int)AdjList[u].size(); j++) {  // we use AdjList here!
                int v = AdjList[u][j];
                if (res[u][v] > 0 && !vis[v])
                    vis[v] = true, q.push(v), p[v] = u;
            }
        }
        //printf("Augmenting thru: ");
        augment(t, INF);
        //printf("\n");
        if (f == 0) break;
        mf += f;
    }
    return mf;
}

void clearGlobs() {
    memset(res, 0, sizeof(res));
    for(int i=0; i<MAX_V; i++)
        AdjList[i].clear();
}

void testCase(int monkCnt) {
    clearGlobs();
    int pondCap;
    vector <int> entrs[limRng];
    vector <int> sals[limRng];
    int nodCnt = monkCnt+2;
    set <int> monkInRng;
    int rngInis[MAX_V], rngTams[MAX_V];
    int rngUsd[MAX_V];
    int reqFl = 0;

    scanf("%d", &pondCap);
    for(int i=0; i<monkCnt; i++) {
        int a, b, c;
        scanf("%d%d%d", &c, &a, &b);
        entrs[a].push_back(i);
        sals[b].push_back(i);
        res[i+2][1] = c;
        AdjList[i+2].push_back(1);
        AdjList[1].push_back(i+2);
        reqFl += c;
    }

    for(int i=0, ult=0; i<limRng; i++) {
        if((!sals[i].empty() || !entrs[i].empty()) && !monkInRng.empty()) {            
            rngInis[nodCnt] = ult;
            rngTams[nodCnt] = i-ult;
            rngUsd[nodCnt] = 0;
            int d = i-ult;
            res[0][nodCnt] = pondCap*d;
            AdjList[0].push_back(nodCnt);
            AdjList[nodCnt].push_back(0);
            for(const int m:monkInRng) {
                res[nodCnt][m+2] = d;
                AdjList[m+2].push_back(nodCnt);
                AdjList[nodCnt].push_back(m+2);
            }
            nodCnt++;
        }
        if(!sals[i].empty()) {
            ult = i;
            for(const int s:sals[i])
                monkInRng.erase(s);
        }
        if(!entrs[i].empty()) {
            ult = i;
            for(const int s:entrs[i])
                monkInRng.insert(s);
        }
    }

    // printf("\n");
    // printf("Rangs are:\n");
    // for(int i=monkCnt+2; i<nodCnt; i++) {
    //     printf("%d %d\n", rngInis[i], rngInis[i] + rngTams[i]);
    // }
    // printf("Graph is:\n");
    // for(int i=0; i<nodCnt; i++) {
    //     printf("%d => ", i);
    //     for(const int &sig:AdjList[i]) {
    //         printf("(%d %d) ", sig, res[i][sig]);
    //     }
    //     printf("\n");
    // }

    int ka = edmond_karps(0, 1);
    //printf("==> (%d)\n", ka);
    reqFl -= ka;
    // for(int i=0; i<nodCnt; i++) {
    //     printf("%d => ", i);
    //     for(const int &sig:AdjList[i]) {
    //         printf("(%d %d) ", sig, res[i][sig]);
    //     }
    //     printf("\n");
    // }

    if(reqFl!=0) {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    for(int i=0; i<monkCnt; i++) {
        vector <pair <int,int>> ans;
        for(const int n:AdjList[i+2]) {
            int w = res[i+2][n];
            if(n==1 || w==0)
                continue;
            int rem = rngTams[n] - rngUsd[n];
            if(w<=rem) {
                ans.push_back(make_pair(rngInis[n] + rngUsd[n], rngInis[n] + rngUsd[n] + w));
            }
            else {
                int d = w - rem;
                ans.push_back(make_pair(rngInis[n] , rngInis[n] + d));
                ans.push_back(make_pair(rngInis[n] + rngUsd[n], rngInis[n] + rngTams[n]));
            }
            rngUsd[n] = (rngUsd[n] + w)%rngTams[n];
        }
        vector <pair <int,int>> ans2;
        int k = ans.size();
        for(int j=0; j<k; j++) {
            int a = ans[j].first;
            while(j+1!=k && ans[j].second==ans[j+1].first) j++;
            ans2.push_back(make_pair(a, ans[j].second));
        }
        printf("%d", (int) ans2.size());        
        for(const auto &p:ans2) {
            printf(" (%d,%d)", p.first, p.second);
        }
        printf("\n");
    }
}

int main() {
    int tc = 0;
    int n;
    while(scanf("%d", &n)!=EOF && n) {
        printf("Case %d: ", ++tc);
        testCase(n);
    }
}
