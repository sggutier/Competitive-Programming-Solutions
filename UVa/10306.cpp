#include <bits/stdc++.h>
using namespace std;
const int limP = 305;
const int inf = 1e9;

int minC[limP+1][limP+1];

void testCase() {
    for(int i=0; i<=limP; i++)
        for(int j=0; j<=limP; j++)
            minC[i][j] = inf;
    minC[0][0] = 0;
    int M, P;

    scanf("%d%d", &M, &P);
    while(M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        for(int i=0; i+a<=limP; i++)
            for(int j=0; j+b<=limP; j++)
                if(minC[i][j] !=inf )
                    minC[i+a][j+b] = min(minC[i+a][j+b], minC[i][j]+1);
    }

    int ans = inf;
    P *= P;
    for(int i=0; i<=limP; i++) {
        for(int j=0; j<=limP; j++) {
            if(i*i  + j*j == P)
                ans = min(ans, minC[i][j]);
        }
    }

    if(ans==inf) {
        printf("not possible\n");
    }
    else {
        printf("%d\n", ans);
    }
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
