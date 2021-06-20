#include <bits/stdc++.h>
using namespace std;
const int limN = 1e2 + 5;

int bigS[limN][limN], bigR[limN], bigC[limN];
int ans[limN][limN];
char S[limN][limN];

void testCase() {
    memset(bigC, 0, sizeof(bigC));
    memset(ans, 0, sizeof(ans));
    
    int rowCnt, colCnt, Q;
    scanf("%d%d%d", &rowCnt, &colCnt, &Q);
    for(int i=1; i<=rowCnt; i++) {
        scanf("%s", S[i]+1);
        bigR[i] = 0;
        for(int j=1; j<=colCnt; j++) {
            bigR[i] = (S[i][j] == S[i][j-1]? bigR[i] : 0)+1;
            bigC[j] = (S[i][j] == S[i-1][j]? bigC[j] : 0)+1;
            if(S[i][j] == S[i-1][j-1])
                bigS[i][j] = max(1, min(bigS[i-1][j-1]+1, min(bigR[i], bigC[j])));
            else
                bigS[i][j] = 1;
            int d = bigS[i][j], k = (d-1)/2;
            d -= (d+1)%2;
            //ans[i-k][j-k] = d;
            for(int w=0; w<=k; w++)
                ans[i-w][j-w] = max(ans[i-w][j-w], w*2+1);
        }
    }

    // for(int i=0; i<=rowCnt; i++) {
    //     for(int j=0; j<=colCnt; j++) {
    //         printf("%2d ", ans[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d %d %d\n", rowCnt, colCnt, Q);
    while(Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", ans[a+1][b+1]);
    }
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
