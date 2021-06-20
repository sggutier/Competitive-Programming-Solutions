#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int inf = (1<<30);

void testCase(int nodeCnt, int edgeCnt, int querCnt) {
    vector <vector<int>> minP(nodeCnt, vector<int>(nodeCnt, inf));
    while(edgeCnt--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        minP[b][a] = minP[a][b] = min(minP[a][b], c);
    }
    for(int i=0; i<nodeCnt; i++)
        minP[i][i] = 0;
    for(int k=0; k<nodeCnt; k++) {
        for(int i=0; i<nodeCnt; i++) {
            for(int j=0; j<nodeCnt; j++) {
                minP[i][j] = min(minP[i][j], max(minP[i][k], minP[k][j]));
            }
        }
    }
    while(querCnt--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        if(minP[a][b]==inf)
            printf("no path\n");
        else
            printf("%d\n", minP[a][b]);
    }
}

int main() {
    int a, b, c;

    for(int tc=1; scanf("%d%d%d", &a, &b, &c)!=EOF && (a || b || c); tc++) {
        if(tc!=1)
            printf("\n");
        printf("Case #%d\n", tc);
        testCase(a, b, c);
    }
}
