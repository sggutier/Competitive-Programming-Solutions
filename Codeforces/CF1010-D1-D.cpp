#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

bool ans[limN];
int sgs[limN][2];

class nodo {
public:
    int id, val ;
    nodo(int id) : id(id), val(0) {}
    virtual int getVal() {
        return val;
    }
    virtual void reco(int r) {
        if(r != val)
            ans[id] = true;
    }
};
typedef nodo* nodop;

class nand : public nodo {
public:
    nodop l, r;
    nand(int id) : nodo(id), l(NULL), r(NULL) {}
    int getVal() {
        val = 1;
        if(l) val &= l->getVal();
        if(r) val &= r->getVal();
        return this->val;
    }
    void reco(int v) {
        // printf("and %d %d\n", id, v);
        if(v==2) {
            l->reco(2), r->reco(2);
            return;
        }
        else if(v==0) {
            l->reco(r->val? 0 : 2);
            r->reco(l->val? 0 : 2);
        }
        else {
            if(r->val)
                l->reco(1);
            if(l->val)
                r->reco(1);
        }
    }
};

class nor : public nodo {
public:
    nodop l, r;
    nor(int id) : nodo(id), l(NULL), r(NULL) {}
    int getVal() {
        val = 0;
        if(l) val |= l->getVal();
        if(r) val |= r->getVal();
        return this->val;
    }
    void reco(int v) {
        if(v==2) {
            l->reco(2), r->reco(2);
            return;
        }
        else if(v==1) {
            l->reco(!r->val? 1 : 2);
            r->reco(!l->val? 1 : 2);
        }
        else {
            if(!r->val)
                l->reco(0);
            if(!l->val)
                r->reco(0);
        }
    }
};

class nxor : public nodo {
public:
    nodop l, r;
    nxor(int id) : nodo(id), l(NULL), r(NULL) {}
    int getVal() {
        val = 0;
        if(l) val ^= l->getVal();
        if(r) val ^= r->getVal();
        return this->val;
    }
    void reco(int v) {
        // printf("xor %d %d\n", id, v);
        if(v==2) {
            l->reco(2), r->reco(2);
            return;
        }
        for(int i=0; i<2; i++) {
            if( (i ^ r->val) == v)
                l->reco(i);
            if( (i ^ l->val) == v)
                r->reco(i);
        }
    }
};

class nnot : public nodo {
public:
    nodop sg;
    nnot(int id) : nodo(id), sg(NULL) {}
    int getVal() {
        return this->val = !sg->getVal();
    }
    void reco(int v) {
        // printf("not %d %d\n", id, v);
        if(v==2) {
            sg->reco(2);
            return;
        }
        sg->reco(!v);
    }
};


nodop arb[limN];

int main() {
    int N ;
    char tmp[20];
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%s", tmp);
        if(tmp[0] == 'A')
            arb[i] = new nand(i);
        else if(tmp[0] == 'I')
            arb[i] = new nodo(i);
        else if(tmp[0] == 'O')
            arb[i] = new nor(i);
        else if(tmp[0] == 'N')
            arb[i] = new nnot(i);
        else if(tmp[0] == 'X')
            arb[i] = new nxor(i);
        scanf("%d", &sgs[i][0]);
        if(tmp[0] != 'I' && tmp[0] != 'N')
            scanf("%d", &sgs[i][1]);
    }

    for(int i=1; i<=N; i++) {
        // printf("%d => ", i);
        if( dynamic_cast<nand*>(arb[i]) != nullptr ) {
            ((nand*) arb[i]) -> l = arb[sgs[i][0]];
            ((nand*) arb[i]) -> r = arb[sgs[i][1]];
            // printf("and :: %d %d\n", sgs[i][0], sgs[i][1]);
        }
        else if( dynamic_cast<nor*>(arb[i]) != nullptr ) {
            ((nor*) arb[i]) -> l = arb[sgs[i][0]];
            ((nor*) arb[i]) -> r = arb[sgs[i][1]];
            // printf("or\n");
        }
        else if( dynamic_cast<nxor*>(arb[i]) != nullptr ) {
            ((nxor*) arb[i]) -> l = arb[sgs[i][0]];
            ((nxor*) arb[i]) -> r = arb[sgs[i][1]];
            // printf("xor\n");
        }
        else if( dynamic_cast<nnot*>(arb[i]) != nullptr ) {
            ((nnot*) arb[i]) -> sg = arb[sgs[i][0]];
            // printf("not\n");
        }
        else {
            // printf("in\n");
            arb[i] -> val = sgs[i][0];
        }
    }

    arb[1] -> getVal();
    arb[1] -> reco(1);

    for(int i=1; i<=N; i++) {
        if( dynamic_cast<nand*>(arb[i]) != nullptr ) {
        }
        else if( dynamic_cast<nor*>(arb[i]) != nullptr ) {
        }
        else if( dynamic_cast<nxor*>(arb[i]) != nullptr ) {
        }
        else if( dynamic_cast<nnot*>(arb[i]) != nullptr ) {
        }
        else
            printf("%d", ans[i]? 1 : 0);
    }
    printf("\n");
}
