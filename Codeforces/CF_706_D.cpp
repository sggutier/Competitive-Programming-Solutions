#include <bits/stdc++.h>
using namespace std;

struct Nodo {
    int cnt;
    Nodo *L, *R;
    Nodo() : cnt(0), L(NULL), R(NULL) {}
    Nodo(int c) : cnt(c), L(NULL), R(NULL) {}
    void mete(const int n, const int pos=30) {
        cnt++;
        if(pos==-1) return;
        if((1<<pos) & n) {
            if(!R) R = new Nodo();
            R->mete(n, pos-1);
        }
        else {
            if(!L) L = new Nodo();
            L->mete(n, pos-1);
        }
    }
    void saca(const int n, const int pos=30) {
        cnt--;        
        if(pos==-1) return;
        if((1<<pos) & n) {
            R->saca(n, pos-1);
            if(R->cnt==0) {
                delete R;
                R = NULL;
            }
        }
        else {
            L->saca(n, pos-1);
            if(L->cnt==0) {
                delete L;
                L = NULL;
            }            
        }
    }
    int maxN(const int n, const int pos=30) {
        if(pos==-1)
            return 0;
        int ans; Nodo *sg;
        if((1<<pos) & n) {
            if(L)
                ans = 1<<pos, sg = L;
            else
                ans = 0, sg = R;
        }
        else {
            if(R)
                ans = 1<<pos, sg = R;
            else
                ans = 0, sg = L;
        }
        return ans + sg->maxN(n, pos-1);
    }
};

Nodo arb;

int main() {
    int Q, n ;
    char c[5];
    arb.mete(0);
    scanf("%d", &Q);
    while(Q--) {
        scanf("%s%d", c, &n);
        switch(c[0]) {
        case '+':
            arb.mete(n);
            break;
        case '-':
            arb.saca(n);
            break;
        default:
            printf("%d\n", arb.maxN(n));
            break;
        }
    }
}
