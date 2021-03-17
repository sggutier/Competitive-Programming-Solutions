#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 4e5 + 5;

int N, K ;
int N2;
int nums[LIM_N];
int acms[LIM_N];

bool works(const int x) {
    static int T = 1;
    static int ks[2 * LIM_N] = {0};
    T++;
    // printf("%d => ", x);
    for(int i=1; i <= N2; i++) {
        acms[i] = acms[i-1] + (nums[i] < x? -1 : 1);
        // printf("%d ", acms[i]);
        if(K <= i) {
            ks[acms[i-K] + LIM_N] = T;
            if(ks[acms[i] - 1 + LIM_N] == T) {
                // printf("OK\n");
                return true;
            }
        }
    }
    // printf("NO\n");
    return false;
}

int main() {
    scanf("%d%d", &N, &K);
    for(int i=1; i <= N; i++) {
        scanf("%d", &nums[i]);
    }
    N2 = N*2;
    int ini=1, fin=N;
    while(ini < fin) {
        int piv = (ini + fin) / 2 + 1;
        if(works(piv))
            ini = piv;
        else
            fin = piv-1;
    }
    printf("%d\n", ini);
}
