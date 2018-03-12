#include <bits/stdc++.h>
#define fs first
#define sn second
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> piii;

int N, M, W, R[5005];
pii D[5005];
piii B[5005];
bool U[5005];

int main() {
    scanf("%d %d", &N, &M);

    for(int i=0;i<N;i++) {
        scanf("%d", &D[i].fs);
        D[i].sn = i;
    }
    sort(D, D + N);

    for(int i=0;i<M;i++)
        scanf("%d", &B[i].fs.sn);
    for(int i=0;i<M;i++)
        scanf("%d", &B[i].fs.fs);
    for(int i=0;i<M;i++)
        B[i].sn = i;
    sort(B, B + M);

//    for(int i=0;i<M;i++)
//        printf("%d %d %d\n", B[i].fs.fs, B[i].fs.sn, B[i].sn);

    W = N;
    for(piii p : B) {
        int i = N - 1;
        while(i >= 0 && (U[i] || p.fs.sn  < D[i].fs)) --i;
        if(i == -1) continue;

        U[i] = true; W--;
        R[D[i].sn] = p.sn + 1;

        if(!W) break;
    }

    if(W) {
        printf("impossible\n");
        return 0;
    }

    for(int i=0;i<N;i++)
        printf("%d%s", R[i], i < N - 1 ? " " : "\n");
    return 0;
}
