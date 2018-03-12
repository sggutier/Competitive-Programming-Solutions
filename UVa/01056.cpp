#include <bits/stdc++.h>
using namespace std;
const int limN = 55;
const int inf = (1<<29);

void testCase(int nodCnt, int edgCnt) {
    int cnt = 0;
    map <string, int> ids;
    int minP[limN][limN];

    for(int i=0; i<nodCnt; i++) {
        for(int j=0; j<nodCnt; j++)
            minP[i][j] = inf;
        minP[i][i] = 0;
    }
    
    for(int i=0; i<edgCnt; i++) {
        char A[limN], B[limN];
        int a, b;
        scanf("%s%s", A, B);
        auto itA=ids.find(A), itB=ids.find(B);
        if(itA == ids.end())
            ids[A] = cnt++;
        if(itB == ids.end())
            ids[B] = cnt++;
        a = ids[A];
        b = ids[B];
        minP[a][b] = minP[b][a] = 1;
    }

    for(int k=0; k<nodCnt; k++)
        for(int i=0; i<nodCnt; i++)
            for(int j=0; j<nodCnt; j++)
                minP[i][j] = min(minP[i][k] + minP[k][j], minP[i][j]);

    int ans = 0;
    for(int i=0; i<nodCnt; i++)
        for(int j=0; j<nodCnt; j++)
            ans = max(ans, minP[i][j]);

    if(ans!=inf)
        printf("%d\n", ans);
    else
        printf("DISCONNECTED\n");
}

int main() {
    int a, b;
    int tc = 0;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b)) {
        printf("Network %d: ", ++tc);
        testCase(a, b);
        printf("\n");
    }
}
