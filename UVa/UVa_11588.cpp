#include <bits/stdc++.h>
using namespace std;
const int limN = 70;

int testCase() {
    int R, C, a, b ;
    int cnts[limN];
    char mat[limN][limN];
    int maxC = 0;
    int ans = 0;

    memset(cnts, 0, sizeof(cnts));

    scanf("%d%d%d%d", &R, &C, &a, &b);
    for(int i=0; i<R; i++) {
        scanf("%s", mat[i]);
        for(int j=0; j<C; j++)
            maxC = max(maxC, ++cnts[mat[i][j]-'A']);
    }

    for(int i=0; i<30; i++)
        ans += cnts[i]==maxC? a*cnts[i] : cnts[i]*b;

    return ans;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: %d\n", i, testCase());
    }
}
