#include <bits/stdc++.h>
using namespace std;
const int limP = 30;
const int limS = 105;

int N;
int arr[limP];
int prims[limS];
bool comp[limS];

void criba(int N = limS-1) {
    for(int i=2; i*i<=N; i++)
        if(!comp[i])
            for(int j=i*i; j<=N; j+=i)
                comp[j] = true;
    int cnt = 0;
    for(int i=2; i<=N; i++) {
        if(comp[i])
            continue;
        for(int j=i; j<=N; j+=i) {
            prims[j] |= (1<<cnt);
        }
        cnt ++;
    }
}

void recur(int rem, int pos=0, int ult=1, int msk=0) {
    // printf("%d (%d) =>", rem, msk);
    // for(int i=0; i<pos; i++)
    //     printf(" %d", arr[i]);
    // printf("\n");
    if(pos==N-1) {
        if(rem<ult || (prims[rem] & msk))
            return;
        for(int i=0; i<pos; i++)
            printf("%d ", arr[i]);
        printf("%d\n", rem);
        return;
    }
    int fin = rem/(N-pos-1);
    for(int i=ult; i<=fin; i++) {
        if(prims[i] & msk)
            continue;
        arr[pos] = i;
        recur(rem-i, pos+1, i, msk | prims[i]);
    }
}

int main() {
    criba();
    int tc;
    int m;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++) {
        scanf("%d%d", &m, &N);
        printf("Case %d:\n", i);
        recur(m);
    }
}
