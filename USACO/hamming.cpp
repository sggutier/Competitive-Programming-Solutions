/*
ID: me60
LANG: C++11
TASK: hamming
*/
#include <bits/stdc++.h>
using namespace std;

int dist(int bitN, int a, int b) {
    int ans = 0;
    for(int i=0; i<bitN; i++) {
        if( ((1<<i) & a) ^ ((1<<i) & b) )
            ans ++;
    }
    return ans;
}

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    
    int N, B, D;
    int ans[70], ansSz = 0;

    scanf("%d%d%d", &N, &B, &D);

    ans[ansSz++] = 0;
    for(int i=1; ansSz<N; i++) {
        bool itWorks = true;
        for(int j=0; j<ansSz; j++) {
            if(dist(B, i, ans[j])<D ) {
                itWorks = false;
                break;
            }
        }
        if(itWorks)
            ans[ansSz++] = i ;
    }

    for(int i=0; i<N; i++) {
        if(i && (i%10)==0)
            printf("\n");
        if(i%10!=0)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}
