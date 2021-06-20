#include <bits/stdc++.h>
using namespace std;
const int limN = 5e2 + 5;

void testCase(int n) {
    int mat[limN][limN];
    long long ans = 0;
    int ord[limN];
    bool usd[limN];

    memset(usd, 0, sizeof(usd));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &mat[i][j]);
    for(int i=0; i<n; i++)
        scanf("%d", &ord[i]);

    for(int w=n-1; w>=0; w--) {
        int k = ord[w];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        usd[k] = true;
        for(int i=0; i<n; i++) {
            if(!usd[i])
                continue;
            for(int j=0; j<n; j++) {
                if(usd[j]) {
                    ans += mat[i][j];
                    //printf("%d %d => %d\n", i, j, mat[i][j]);
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int n, tc ;
    scanf("%d", &tc);
    for(; tc && scanf("%d", &n)!=EOF; tc--)
        testCase(n);
}
