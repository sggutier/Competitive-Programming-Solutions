#include <bits/stdc++.h>
using namespace std;
const int limN = 21;
#define ll long long

ll mat[limN][limN][limN];

inline ll getRect(int z, int lx, int ly, int rx, int ry) {
    lx --, ly --;
    return mat[z][rx][ry] + mat[z][lx][ly] - mat[z][lx][ry] - mat[z][rx][ly];
}

void testCase() {
    int X, Y, Z;
    long long ans;
    scanf("%d%d%d", &Z, &X, &Y);
    for(int i=1; i<=Z; i++) {
        for(int j=1; j<=X; j++) {
            for(int k=1; k<=Y; k++) {
                scanf("%lld", &mat[i][j][k]);
                mat[i][j][k] += mat[i][j-1][k] + mat[i][j][k-1] - mat[i][j-1][k-1];
            }
        }
    }
    ans = mat[1][1][1] ;
    for(int lx=1; lx<=X; lx++) {
        for(int ly=1; ly<=Y; ly++) {
            for(int rx=lx; rx<=X; rx++) {
                for(int ry=ly; ry<=Y; ry++) {
                    long long sum = 0LL;
                    for(int z=1; z<=Z; z++) {
                        sum += getRect(z, lx, ly, rx, ry);
                        ans = max(ans, sum);
                        if(sum<0)
                            sum = 0LL;
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i) printf("\n");
        testCase();
    }
}
