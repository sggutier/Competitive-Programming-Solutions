#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

void testCase() {
    int N, E;
    int minP[limN][limN];
    int ini, fin;

    scanf("%d%d", &N, &E);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            minP[i][j] = (1<<29);
        minP[i][i] = 0;
    }
    for(int i=0; i<E; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        minP[b][a] = minP[a][b] = 1;
    }
    scanf("%d%d", &ini, &fin);

    for(int k=0; k<N; k++)
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                minP[i][j] = min(minP[i][j], minP[i][k] + minP[k][j]);

    int ans = 0;
    for(int k=0; k<N; k++) {
        ans = max(ans, minP[ini][k] + minP[k][fin]);
    }
    printf("%d\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
}
