#include <bits/stdc++.h>
using namespace std;

struct UFindNode {
    int id;
    UFindNode *parent ;
    UFindNode() {
        parent = NULL;
    }
    UFindNode(int k) {
        id = k;
        parent = NULL;
    }
    UFindNode* root() {
        if(parent==NULL)
            return this;
        return parent = parent -> root();
    }
    bool join(UFindNode* B) {
        UFindNode* A = this->root();
        B = B->root();
        if(A==B)
            return false;
        B -> parent = A;
        return true;
    }
};

void testCase() {
    int N, M;
    scanf("%d%d", &N, &M);
    int debts[N];
    UFindNode nods[N];

    for(int i=0; i<N; i++) {
        scanf("%d", &debts[i]);
        nods[i].id = i;
    }
    for(int i=0; i<M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int x=nods[a].root()->id, y=nods[b].root()->id;
        nods[a].join(&nods[b]);
        // printf("%d %d => %d %d (%d %d)\n", a, b, x, y, debts[x], debts[y]);
        int z = nods[x].root()->id;
        int d = debts[x];
        debts[x] -= d;
        debts[z] += d;
        d = debts[y];
        debts[y] -= d;
        debts[z] += d;
    }
    for(int i=0; i<N; i++) {
        if(debts[i]) {
            printf("IMPOSSIBLE\n");
            return;
        }
    }
    printf("POSSIBLE\n");
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    return 0;
}
