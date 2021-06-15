#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e6 ;

int N ;
int cnt[2 * LIM_N + 5];

int main() {
    int K ;
    int minV = LIM_N;

    scanf("%d%d", &N, &K);
    for(int i=0, a; i < N; i++) {
        scanf("%d", &a);
        minV = min(minV, a);
        cnt[a] ++;
    }
    for(int i=1, R=2*LIM_N + 5; i < R; i++)
        cnt[i] += cnt[i-1];

    for(int g=minV; g > 1; g--) {
        bool wks = true ;
        if(K < g-1) {
            for(int l = K, r = g-1; l <= LIM_N; l+=g, r +=g) {
                if(cnt[l] != cnt[r]) {
                    wks = false;
                    break;
                }
            }

        }
        if(wks) {
            printf("%d\n", g);
            return 0 ;
        }
    }

    printf("1\n");
}
