#include <bits/stdc++.h>
using namespace std;
const int limL = 1e5 + 5;
const int limN = 12;

int nms[limN][limL];
int posos[limN][limL];

int main() {
    int L, N ;
    scanf("%d%d", &L, &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<L; j++) {
            scanf("%d", &nms[i][j]);
            posos[i][ nms[i][j] ] = j;
        }
    }

    long long ans = 0;

    for(int w=L-1, l = 0; w>=0; w--) {
        int c = nms[0][w];
        for(int i=1; i<N; i++) {
            if(nms[i][ posos[i][c] + 1] != nms[0][w+1]) {
                l = 0;
                break;
            }
        }
        l++;
        ans += l;
    }

    printf("%lld\n", ans);
}
