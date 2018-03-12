#include <bits/stdc++.h>
using namespace std;
const int limN = 8008;

int N;
int A[limN], B[limN], C[limN];
int ordo[limN];
int sigL[limN], sigR[limN];

bool funca(int u=0, int l=0, int r=N-1) {
    int k = ordo[A[u]], p = A[u];
    // printf("%d [%d %d] => %d %d\n", p, k, u, l, r);
    if(k < l || r < k)
        return false;
    sigL[p] = sigR[p] = 0;
    if(k != l) {
        sigL[p] = A[u+1];
        if(!funca(u+1, l, k-1))
            return false;
    }
    if(k != r) {
        sigR[p] = A[u+k-l+1];
        if(!funca(u+k-l+1, k+1, r))
            return false;
    }
    return true;
}

bool checaPosO(int pos, int &w) {
    if(sigL[pos])
        if(!checaPosO(sigL[pos], w))
            return false;
    if(sigR[pos])
        if(!checaPosO(sigR[pos], w))
            return false;
    return B[w++] == pos;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &B[i]);
    for(int i=0; i<N; i++) {
        scanf("%d", &C[i]);
        ordo[C[i]] = i;
    }

    int k = 0;
    printf("%s\n", funca()  && checaPosO(A[0], k)? "yes" : "no");
}
