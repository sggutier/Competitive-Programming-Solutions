#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
#define ll long long
#define mp make_pair

ll mat[limN][limN];

inline ll getRect(int lx, int ly, int rx, int ry) {
    lx--, ly--;
    return mat[rx][ry] + mat[lx][ly] - mat[rx][ly] - mat[lx][ry];
}

void testCase() {
    int rows, cols;
    long long k;
    pair <int,long long> ans = mp(0, 0LL);
    scanf("%d%d%lld", &rows, &cols, &k);
    for(int i=1; i<=rows; i++) {
        for(int j=1; j<=cols; j++) {
            scanf("%lld", &mat[i][j]);
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }
    for(int lx=1; lx<=rows; lx++) {
        for(int ly=1; ly<=cols; ly++) {
            for(int rx=lx; rx<=rows; rx++) {
                for(int ry=ly; ry<=cols; ry++) {
                    long long w = getRect(lx, ly, rx, ry);
                    if(w<=k)
                        ans = max(ans, mp((ry-ly+1)*(rx-lx+1), -w));
                }
            }
        }
    }
    printf("%d %lld\n", ans.first, -ans.second);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        printf("Case #%d: ", i+1);
        testCase();
    }
}
