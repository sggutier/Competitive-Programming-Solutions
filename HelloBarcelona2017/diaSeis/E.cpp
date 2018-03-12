#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

struct pNode {
    int mM, tM;
    pNode *sig ;
    pNode() {
    }
    pNode(int m) {
        mM = m;
        tM = m;
        sig = NULL;
    }
    pNode(pNode* s, int m) {
        if(m) {
            mM = m;
            sig = s;
            tM = m + s->tM;
        }
        else {
            mM = s->sig->mM;
            tM = s->sig->tM;
            sig = s->sig->sig;
        }
    }
};

pNode *nods[limN];

int main() {
    nods[0] = new pNode(0);
    
    int N ;
    long long ans = 0LL;

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        nods[i] = new pNode(nods[a], b);
        ans += nods[i]->tM;
    }

    printf("%lld\n", ans);
}
