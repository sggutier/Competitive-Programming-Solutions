#include <bits/stdc++.h>
using namespace std;
const int limN = 1005;

int R, C ;
char mat[limN][limN];
int usdR[limN], usdC[limN];
int ans[limN][limN];

void testCase() {
    scanf("%d%d", &R, &C);
    for(int i=0; i<R; i++) {
        scanf("%s", mat[i]);
        usdR[i] = 0;
        for(int j=0; j<C; j++) {
            usdC[j] = 0;
            ans[i][j] = mat[i][j]=='0'? -1 : 0;
        }
    }

    for(int w=1; w<=2; w++) {
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) if(ans[i][j] != -1) {
                    usdR[i] = 1;
                    usdC[j] = 1;
                }
        }
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(ans[i][j] != -1) continue;
                if(usdR[i] || usdC[j])
                    ans[i][j] = w;
            }
        }
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(j)
                printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc; tc--)
        testCase();
}
