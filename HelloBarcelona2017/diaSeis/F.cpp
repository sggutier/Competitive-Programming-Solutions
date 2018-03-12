#include <bits/stdc++.h>
using namespace std;
const int limB = 19;
const int limN = 2e5 + 5;

struct PQueNode {
    int val, cant;
    PQueNode *anc[limB];
    PQueNode* ancK(int k) {
        PQueNode* pos = this;
        for(int i=0; i+1<limB; i++)
            if( (1<<i) & k)
                pos = pos->anc[i+1];
        return pos;
    }
    void nuevo(int v, int c, PQueNode *p) {
        val = v;
        cant = c;
        anc[0] = this;
        anc[1] = p;
        for(int i=2; i<limB; i++) {
            if(anc[i-1])
                anc[i] = anc[i-1]->anc[i-1];
            else
                anc[i] = NULL;
        }
    }
};

PQueNode arb[limN];

void push(PQueNode *p, PQueNode *nov, int val) {
    nov->nuevo(val, p->cant+1, p);
}

int pop(PQueNode *p, PQueNode *nov) {
    nov->nuevo(p->val, p->cant-1, p->anc[1]);
    return p->ancK(p->cant-1)->val;
}

int main() {
    for(int i=0; i<limB; i++)
        arb[0].anc[i] = NULL;
    arb[0].val = 0;
    arb[0].cant = 0;
    
    int Q ;
    int a, b, c;

    scanf("%d", &Q);
    
    for(int i=1; i<=Q; i++) {
        scanf("%d%d", &a, &b);
        if(a==1) {
            scanf("%d", &c);
            push(&arb[b], &arb[i], c);
        }
        else {
            printf("%d\n", pop(&arb[b], &arb[i]));
        }
    }
}
