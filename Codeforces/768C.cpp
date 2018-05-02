#include <bits/stdc++.h>
using namespace std;
const int limB = 1024;
const int limN = 1e5 + 5;

int N, K, X;
int _na[limN], _nb[limN];

void calca(int *cur, int *prv) {
    for(int i=0; i<limB; i++)
        cur[i] = 0;
    for(int i=0, s=0; i<limB; i++) {
        int w = prv[i] / 2;
        if(s%2==0 && prv[i]%2)
            w++;
        cur[i ^ X] += w;
        cur[i] += prv[i] - w;
        s += prv[i];
    }
}

int main() {
    int *cur = _na, *prv = _nb;

    scanf("%d%d%d", &N, &K, &X);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        cur[a]++;
    }

    for(; K; K--) {
        swap(cur, prv);
        calca(cur, prv);        
        // for(int i=0; i<limB; i++) {
        //     for(int j=0; j<cur[i]; j++)
        //         printf("%d ", i);
        // }
        // printf("\n");
    }

    int mino = limB-1, maxo = 0;
    for(int i=0; i<limB; i++) {
        if(!cur[i]) continue;
        mino = min(i, mino);
        maxo = i;
    }

    printf("%d %d\n", maxo, mino);
}
