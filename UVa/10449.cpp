#include <bits/stdc++.h>
using namespace std;
const int limN = 205;
const int inf = 1e9;

int N;
int busi[limN];
vector <int> adj[limN];

void bFord(int ini, int* minP) {
    for(int i=0; i<N; i++)
        minP[i] = inf;
    minP[ini] = 0;
    for(int w=0; w<N; w++) {
        // for(int i=0; i<N; i++)
        //     printf("%d ", minP[i]);
        for(int pos=0; pos<N; pos++) {
            if(minP[pos]==inf)
                continue;
            for(const int &sig:adj[pos]) {
                int d = busi[sig] - busi[pos];
                d = d*d*d;
                minP[sig] = min(minP[sig], minP[pos] + d);
            }
        }
        //printf("\n");
    }
    for(int w=0; w<N; w++) {
        for(int pos=0; pos<N; pos++) {
            if(minP[pos]==inf)
                continue;
            for(const int &sig:adj[pos]) {
                int d = busi[sig] - busi[pos];
                d = d*d*d;
                if(d + minP[pos] < minP[sig])
                    minP[sig] = 0;
            }
        }
    }
}

void testCase() {
    int minP[limN];
    int E;

    for(int i=0; i<N; i++) {
        adj[i].clear();
        scanf("%d", &busi[i]);
    }

    scanf("%d", &E);
    for(int i=0; i<E; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
    }
    
    bFord(0, minP);

    scanf("%d", &E);
    for(int i=0; i<E; i++) {
        int a;
        scanf("%d", &a);
        a--;
        if(minP[a]%inf<3)
            printf("?\n");
        else
            printf("%d\n", minP[a]);
    }
}

int main() {
    int tc=0;
    while(scanf("%d", &N)==1) {
        printf("Set #%d\n", ++tc);
        testCase();
    }
}
