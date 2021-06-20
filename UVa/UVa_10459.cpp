#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5e3 + 5;
#define par pair<int,int>
#define f first
#define s second

int N;
list <int> adj[MAX_N];
par maxDst[MAX_N][2];
bool usd[MAX_N];
int minAns, maxAns;
vector <int> ansA, ansB;

int calcMaxDep(int pos=0) {
    usd[pos] = true;
    for(const int &sig:adj[pos]) {
        if(usd[sig])
            continue;
        par tmp = par(calcMaxDep(sig)+1, sig);
        if(tmp>maxDst[pos][1]) {
            maxDst[pos][1] = tmp;
            if(maxDst[pos][1] > maxDst[pos][0])
                swap(maxDst[pos][1], maxDst[pos][0]);
        }
    }
    // printf("%d =>", pos+1);
    // printf("(%d %d) ", maxDst[pos][0].f, maxDst[pos][0].s+1);
    // printf("(%d %d)\n", maxDst[pos][1].f, maxDst[pos][1].s+1);
    return maxDst[pos][0].f;
}

void waruku(int pos=0, int sum=0) {
    int maxD = max(sum, maxDst[pos][0].f);
    //printf("%d => %d\n", pos+1, maxD);
    if(maxAns < maxD) {
        maxAns = maxD;
        ansB.clear();
    }
    if(maxAns == maxD)
        ansB.push_back(pos);
    if(minAns > maxD) {
        minAns = maxD;
        ansA.clear();
    }
    if(minAns == maxD)
        ansA.push_back(pos);
    
    usd[pos] = true;
    for(const int &sig:adj[pos]) {
        if(usd[sig])
            continue;
        if(sig==maxDst[pos][0].s)
            waruku(sig, max(maxDst[pos][1].f, sum)+1);
        else
            waruku(sig, max(maxDst[pos][0].f, sum)+1);
    }
}

void testCase() {
    for(int i=0; i<N; i++) {
        adj[i].clear();
        maxDst[i][0] = maxDst[i][1] = par(0, -1);
    }
    memset(usd, 0, sizeof(usd));
    minAns = (1<<30), maxAns = -(1<<30);    
    
    for(int i=0; i<N; i++) {
        int K;
        scanf("%d", &K);
        for(int j=0; j<K; j++) {
            int tmp;
            scanf("%d", &tmp);
            adj[i].push_back(tmp-1);
        }
    }

    calcMaxDep();
    memset(usd, 0, sizeof(usd));
    waruku();
    sort(ansA.begin(), ansA.end());
    sort(ansB.begin(), ansB.end());

    printf("Best Roots  :");
    for(const int &v:ansA)
        printf(" %d", v+1);
    printf("\n");
    printf("Worst Roots :");
    for(const int &v:ansB)
        printf(" %d", v+1);
    printf("\n");
}

int main() {
    while(scanf("%d", &N)!=EOF)
        testCase();
}
