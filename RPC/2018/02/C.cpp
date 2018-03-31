#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int limN = 1e5 + 5;

struct Nodo {
    int id;
    int cols[3];
    Nodo *antC[3], *sigC[3];
    int unq ;
    Nodo(int a, int b, int c, int id) : id(id) {
        for(int i=0; i<3; i++) antC[i] = sigC[i] = NULL;
        cols[0] = a;
        cols[1] = b;
        cols[2] = c;
    }
    int calcDst(int x) {
        return x==0? 360 : (x+360)%360;
    }
    void recalca() {
        unq = 0;
        for(int i=0; i<3; i++)
            if(antC[i]->cols[i] != cols[i] && sigC[i]->cols[i] != cols[i])
                unq += calcDst(-antC[i]->cols[i] + sigC[i]->cols[i]);
    }
    void quita() {
        for(int i=0; i<3; i++) {
            antC[i]->sigC[i] = sigC[i];
            sigC[i]->antC[i] = antC[i];
        }
        for(int i=0; i<3; i++) {
            sigC[i]->recalca();
            antC[i]->recalca();
        }
    }
};
typedef Nodo* NodoP;
typedef pair<int, int> pii;
typedef pair< pii, NodoP> pn;

NodoP nodos[limN];
set <pn> Q;

int popQ() {
    NodoP n = Q.begin()->s;
    if(!Q.empty() ) {
        Q.erase(Q.begin());
        // printf("=> %d\n", n->unq);
        // n->recalca();
        // printf("=> %d\n", n->unq);
        for(int i=0; i<3; i++) {
            Q.erase(pn(pii(n->sigC[i]->unq, -n->sigC[i]->id), n->sigC[i]));
            Q.erase(pn(pii(n->antC[i]->unq, -n->antC[i]->id), n->antC[i]));
            // printf("\t %d (%d %d %d) %d | %d (%d %d %d) %d\n", n->antC[i]->id, n->antC[i]->cols[0], n->antC[i]->cols[1], n->antC[i]->cols[2], n->antC[i]->unq,
            //        n->sigC[i]->id, n->sigC[i]->cols[0], n->sigC[i]->cols[1], n->sigC[i]->cols[2], n->sigC[i]->unq);
        }
        n->quita();
        for(int i=0; i<3; i++) {
            Q.insert(pn(pii(n->sigC[i]->unq, -n->sigC[i]->id), n->sigC[i]));
            Q.insert(pn(pii(n->antC[i]->unq, -n->antC[i]->id), n->antC[i]));
        }
    }
    
    return n->id;
}

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=0, a, b, c, id; i<N; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &id);
        nodos[i] = new Nodo(a, b, c, id);
    }

    for(int i=0; i<3; i++) {
        sort(nodos, nodos+N, [i](const NodoP &x, const NodoP &y) { return x->cols[i] < y->cols[i]; } );
        for(int j=0; j<N; j++) {
            nodos[j]->sigC[i] = nodos[(j+1)%N];
            nodos[j]->antC[i] = nodos[(j+N-1)%N];
        }
    }

    for(int i=0; i<N; i++) {
        nodos[i]->recalca();
        // printf("Nodo (%d) : %d %d %d || %d\n", nodos[i]->id, nodos[i]->cols[0], nodos[i]->cols[1], nodos[i]->cols[2], nodos[i]->unq);
        // for(int c=0; c<3; c++) {
        //     printf("\t%d %d\n", nodos[i]->antC[c]->id, nodos[i]->sigC[c]->id);
        // }
        Q.insert(pn(pii(nodos[i]->unq, -nodos[i]->id), nodos[i]));
    }

    for(int i=0; i<N; i++)
        printf("%d\n", popQ());
}
