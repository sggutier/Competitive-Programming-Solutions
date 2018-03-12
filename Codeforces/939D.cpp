#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

struct Nodo {
    char id;
    Nodo* prev;
    Nodo() : prev(NULL) {}
    Nodo(int w) : id(w) {
    }
    Nodo* root() {
        if(prev==NULL)
           return this;
        return prev = prev->root();
    }
    void une(Nodo *b) {
        Nodo *a = this->root();
        b = b->root();
        if(a!=b)
            b->prev = a;
    }
};

Nodo grf[300];

int main() {
    int N ;
    char A[limN], B[limN];
    int ans = 0;

    scanf("%d", &N);
    scanf("%s", A);
    scanf("%s", B);

    for(int i=0; i<300; i++)
        grf[i].id = i;

    for(int i=0; i<N; i++)
        grf[(int) A[i]].une(&grf[(int) B[i]]);

    for(int i=0; i<300; i++)
        if(grf[i].root() != &grf[i])
            ans ++;

    printf("%d\n", ans);
    for(int i=0; i<300; i++)
        if(grf[i].root() != &grf[i])
            printf("%c %c\n", i, grf[i].root()->id);
}
