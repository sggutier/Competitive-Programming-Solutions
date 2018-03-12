#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

static int mat[limN][limN];
static int sums[limN][limN];

void testCase(int rowCnt, int colCnt) {
    for(int i=1; i<=rowCnt; i++) {
        for(int j=1; j<=colCnt; j++) {
            scanf("%d", &mat[i][j]);
            sums[i][j] = mat[i][j]? 0 : sums[i-1][j] + 1;
        }
    }
    int ans = 0;
    for(int a=0; a<=rowCnt; a++) {
        for(int b=a+1; b<=rowCnt; b++) {
            int maxV = 0, dst=b-a;
            for(int j=1, v=0; j<=colCnt; j++) {
                if(sums[b][j] - sums[a][j]==dst) {
                    v ++;
                    maxV = max(maxV, v);
                }
                else
                    v = 0;
            }
            ans = max(ans, dst*maxV);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
    
    return 0;
}
