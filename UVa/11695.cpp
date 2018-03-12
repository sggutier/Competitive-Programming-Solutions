#include <bits/stdc++.h>
using namespace std;
const int limN = 2505;
typedef pair<int,int> par;
#define f first
#define s second

int N;
vector <par> AdjList[limN];

par calcDiam(int pos, int forb) {
    vector <int> minP(N, 0);
    vector <int> ant(N, -1);
    queue <int> Q;
    minP[pos] = 1;
    Q.push(pos);
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        for(const par &sig:AdjList[pos]) {
            if(sig.s == forb || minP[sig.f])
                continue;
            minP[sig.f] = 1;
            Q.push(sig.f);
        }
    }

    vector <int> stps;
    minP.assign(N, 0);
    minP[pos] = 1;
    Q.push(pos);
    //printf("Set of\n");
    while(!Q.empty()) {
        pos = Q.front(); Q.pop();
        int d = minP[pos] + 1;
        //printf("%d %d\n", pos, d-2);
        for(const par &sig:AdjList[pos]) {
            if(sig.s == forb || minP[sig.f])
                continue;
            minP[sig.f] = d;
            Q.push(sig.f);
            ant[sig.f] = pos;
        }
    }

    //printf("Path is");
    int fin = pos;
    while(pos!=-1) {
        stps.push_back(pos);
        //printf(" %d", pos);
        pos = ant[pos];
    }
    //printf("\n");

    return par(minP[fin]-1, stps[stps.size()/2]);
}

void testCase() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        AdjList[i].clear();
    par edgs[limN];
    for(int i=1; i<N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        AdjList[a].push_back(par(b, i));
        AdjList[b].push_back(par(a, i));
        edgs[i] = par(a,b);
    }

    int ans = (1<<30);
    int ansId=0, ansA=0, ansB=0;
    for(int i=1; i<N; i++) {
        par A = calcDiam(edgs[i].f, i);
        par B = calcDiam(edgs[i].s, i);
        int x = A.f;
        int y = B.f;
        if(x<y)
            swap(x, y);
        int mx = x/2 + x%2, my = y/2 + y%2;
        int w =  max(x, mx + my + 1);
        if(w<ans) {
            ans = w;
            ansId = i;
            ansA = A.s;
            ansB = B.s;
        }
    }

    printf("%d\n", ans);
    printf("%d %d\n", edgs[ansId].f+1, edgs[ansId].s+1);
    printf("%d %d\n", ansA+1, ansB+1);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
