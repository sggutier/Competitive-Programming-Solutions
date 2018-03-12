#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6;

bool gana[limN + 5];

void precarga(int K, int L, int n=limN) {
    for(int i=1; i<=n; i++)
        gana[i] = !gana[i-1] || (i >= K && !gana[i-K]) || (i >= L && !gana[i-L]);
}

int main() {
    int L, K, N;
    scanf("%d%d%d", &L, &K, &N);
    precarga(L, K);
    for(int i=0; i<N; i++) {
        int w ;
        scanf("%d", &w);
        printf("%c", gana[w]? 'A' : 'B');
    }
    printf("\n");
}
