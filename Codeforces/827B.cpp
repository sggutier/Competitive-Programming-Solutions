#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

int padr[limN];

int calcDep(int n, int k) {
    if(n==1) {
        return 0;
    }
    if(n==2) {
        padr[2] = 1;
        return 1;
    }
    int s = n-k>=3? min(n-k-1, k) : n-k;
    int u = n-k-s+1, v = n-k+1 ;
    // printf("%d %d => %d %d %d\n", n, k, s, u, v);
    // getchar();
    int w = calcDep(n-k, s);
    for(int i=0; i<k; i++)
        padr[v+i] = u + i%s;
    return w+2;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    printf("%d\n", calcDep(N, K));
    for(int i=1; i<=N; i++)
        if(padr[i])
            printf("%d %d\n", i, padr[i]);
}
