#include <bits/stdc++.h>
using namespace std;
const int limN = 2005;

int R, C, K;
char mapa[limN][limN];

int main() {
    int ans = 0;
    
    scanf("%d%d%d", &R, &C, &K);
    for(int i=0; i<R; i++)
        scanf("%s", mapa[i]);

    for(int i=0; i<R; i++) {
        for(int j=0, u=-1; j<C; j++) {
            if(mapa[i][j]=='*') {
                u = j;
                continue;
            }
            if(j-u >= K)
                ans ++;
        }
    }

    if(K > 1) {
        for(int j=0; j<C; j++) {
            for(int i=0, u=-1; i<R; i++) {
                if(mapa[i][j]=='*') {
                    u = i;
                    continue;
                }
                if(i-u >= K)
                    ans ++;
            }
        }
    }

    printf("%d\n", ans);
}
