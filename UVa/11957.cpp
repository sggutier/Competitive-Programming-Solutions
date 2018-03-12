#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int mod = 1000007;

int N;
int ways[limN][limN];
char mapa[limN][limN];

void testCase() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%s", mapa[i]);
        for(int j=0; j<N; j++)
            ways[i][j] = mapa[i][j]=='W';
    }
    for(int i=N-1; i; i--) {
        for(int j=0; j<N; j++) {
            ways[i][j] %= mod;
            for(int d=-1; d<=1; d+=2) {
                if(0 <= j+d && j+d<N) {
                    if(mapa[i-1][j+d]=='.')
                        ways[i-1][j+d] += ways[i][j];
                    else if(i>1 && 0 <= j + 2*d && j + 2*d <N && mapa[i-2][j+2*d]=='.')
                        ways[i-2][j+2*d] += ways[i][j];
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++) {
        ans = (ans + ways[0][i])%mod;
    }

    printf("%d\n", ans);
}

int main() {
    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        printf("Case %d: ", i);
        testCase();
    }
    
    return 0;
}
