#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define tri pair<int, par>
#define w first
#define tip second.first
#define v second.second
const int nodCnt = 26;
const int inf = (1<<30);

void dijkstra(const vector<list<tri>> &neighs, int pos, int T, vector<int> &minP) {
    priority_queue <par> Q;
    minP[pos] = 1;
    Q.push(par(-1, pos));
    while(!Q.empty()) {
        int pos=Q.top().second, dst=-Q.top().first; Q.pop();
        if(minP[pos] < dst)
            continue;        
        for(const auto &sig:neighs[pos]) {
            if(sig.tip == T && (!minP[sig.v] || dst + sig.w < minP[sig.v])) {
                minP[sig.v] = dst + sig.w;
                Q.push(par(-minP[sig.v], sig.v));
            }
        }
    }
}

void testCase(int edgCnt) {
    vector<list<tri>> neighs(nodCnt);
    while(edgCnt--) {
        char A[5], B[5], C[5], D[5];
        int w, a, b, tipo;
        scanf("%s%s%s%s%d", A, B, C, D, &w);
        a = C[0]-'A', b = D[0]-'A';
        tipo = A[0]=='Y';
        neighs[a].push_back(tri(w, par(tipo, b)));
        if(B[0]!='U')
            neighs[b].push_back(tri(w, par(tipo, a)));
    }
    char tmpA[5], tmpB[5];    
    int startPos[2], ans = inf;
    vector <int> minP[2] = {vector<int>(nodCnt), vector<int>(nodCnt)};

    scanf("%s%s", tmpA, tmpB);
    startPos[0] = tmpB[0]-'A';
    startPos[1] = tmpA[0]-'A';

    // printf("%c %c\n", startPos[0] + 'A', startPos[1] + 'A');
    // for(int i=0; i<nodCnt; i++) {
    //     if((int) neighs[i].size() == 0)
    //         continue;
    //     printf("%c =>", i+'A');
    //     for(const auto &sig:neighs[i])
    //         printf(" [%c %d %d]", sig.v + 'A', sig.w, sig.tip);
    //     printf("\n");
    // }
    for(int i=0; i<2; i++)
        dijkstra(neighs, startPos[i], i, minP[i]);

    for(int i=0; i<nodCnt; i++)
        if(minP[0][i] && minP[1][i] )
            ans = min(ans, minP[0][i] + minP[1][i] - 2);

    if(ans==inf) {
        printf("You will never meet.\n");
        return;
    }

    printf("%d", ans);
    for(int i=0; i<nodCnt; i++)
        if(minP[0][i] && minP[1][i] && minP[0][i] + minP[1][i] - 2==ans)
            printf(" %c", i+'A');
    printf("\n");
}

int main() {
    int k;
    
    while(scanf("%d", &k)!=EOF && k)
        testCase(k);
    
    return 0;
}
