#include <bits/stdc++.h>
using namespace std;
const int limN = 2005;

int R, C, K ;
int mat[limN][limN];
int maxH[limN][10], minH[limN][10];
bool hasNum[limN][10];
int ans[10][10];

int main() {
    int S ;

    scanf("%d%d%d%d", &R, &C, &K, &S);
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            scanf("%d", &mat[i][j]);
            if(!hasNum[i][mat[i][j]]) {
                minH[i][mat[i][j]] = j;
                hasNum[i][mat[i][j]] = true;
            }
            maxH[i][mat[i][j]] = j;
        }
        for(int a=1; a<=K; a++) {
            if(!hasNum[i][a]) continue;
            for(int b=1; b<=K; b++) {
                if(!hasNum[i][b]) continue;
                ans[a][b] = ans[b][a] = max(ans[b][a],
                                            abs(maxH[i][a] - minH[i][b]));
            }
        }
    }

    for(int i=0; i<R; i++) {
        for(int j=i+1; j<R; j++) {
            for(int a=1; a<=K; a++) {
                if(!hasNum[i][a]) continue;
                for(int b=1; b<=K; b++) {
                    if(!hasNum[j][b]) continue;
                    // printf("considerando %d %d, %d %d => %d %d\n", i, j, a, b, maxH[i][a], minH[j][b]);
                    ans[a][b] = ans[b][a] = max(ans[b][a],
                                                j-i
                                                + max(abs(maxH[i][a] - minH[j][b]),
                                                      abs(minH[i][a] - maxH[j][b])));
                }
            }
        }
    }

    int mx = 0;
    for(int i=0, u=-1, w; i<S; u = w, i++) {
        scanf("%d", &w);
        if(!i) continue;
        mx = max(mx, ans[u][w]);
    }

    printf("%d\n", mx);
}
