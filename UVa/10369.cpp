#include <bits/stdc++.h>
using namespace std;
const int limN = 505;
#define par pair<int, int>
#define tri pair<double, par>
#define f first
#define s second

struct UFindNode {
    UFindNode *parent;
    UFindNode() {
        parent = NULL;
    }
    bool isRoot() {
        return parent == NULL;
    }
    UFindNode *getRoot() {
        if(this->isRoot())
            return this;
        return parent = parent->getRoot();
    }
    bool join(UFindNode *B) {
        UFindNode *A = this->getRoot();
        B = B->getRoot();
        if(A==B)
            return false;
        B->parent = A;
        return true;
    }
};

double calc_dst(par A, par B) {
    return hypot(A.f - B.f, A.s - B.s);
}

void testCase() {
    int K, N, N2;
    scanf("%d%d", &K, &N);
    N2 = N*N;
    par pts[N];
    tri dsts[N2];
    UFindNode nods[N];

    for(int i=0; i<N; i++) {
        scanf("%d%d", &pts[i].f, &pts[i].s);
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            dsts[i*N + j] = tri(calc_dst(pts[i], pts[j]), par(i, j));
        }
    }
    sort(dsts, dsts+N2);

    double ans = 0.0;
    K = N-K;
    for(int i=0; i<N2 && K; i++) {
        double d = dsts[i].f ;
        int x = dsts[i].s.f, y = dsts[i].s.s;
        if(nods[x].join(&nods[y])) {
            // printf("%d and %d, with %.2lf\n", x+1, y+1, d);
            ans = d;
            K --;
        }
    }

    printf("%.2lf\n", ans);
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--)
        testCase();
}
