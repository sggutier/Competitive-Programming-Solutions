#include <bits/stdc++.h>
#define MAXM 1000000
using namespace std;

struct PST {
    int val, ini, fin;
    PST *l = NULL, *r = NULL;
};

PST* copyTree(PST* tree) {
    PST* nv = new PST();

    nv->ini = tree->ini;
    nv->fin = tree->fin;
    nv->l = tree->l;
    nv->r = tree->r;
    nv->val = tree->val;

    return nv;
}
PST* create(vector<int> &data, int ini, int fin) {
    PST* tree = new PST();
    tree->ini = ini;
    tree->fin = fin;

    if(ini == fin)  {
        tree->val = (ini <= data.size()) ? data[ini-1] : 0;
    }
    else {
        int mid = (ini + fin) / 2;
        tree->l = create(data, ini, mid);
        tree->r = create(data, mid + 1, fin);
    }
    return tree;
}
PST* createFromTree(PST* tree, int i, int x){
    PST* nv = copyTree(tree);
    PST* i_t = tree;
    PST* i_n = nv;

    while(i_t->ini != i_t->fin) {
        int mid = (i_t->ini + i_t->fin) / 2;

        if(i <= mid) {
            i_n->l = copyTree(i_t->l);

            i_n = i_n->l;
            i_t = i_t->l;
        } else {
            i_n->r = copyTree(i_t->r);

            i_n = i_n->r;
            i_t = i_t->r;
        }
    }
    i_n->val = x;

    return nv;
}
int getValue(PST* tree, int i) {
    PST* i_t = tree;
    while(i_t->ini != i_t->fin) {
        int mid = (i_t->ini + i_t->fin) / 2;
        if(i <= mid)
            i_t = i_t->l;
        else
            i_t = i_t->r;
    }
    return i_t->val;
}

int N, M, CR = 2, X, Y, Z;
PST* roots[MAXM + 5];
vector <int> arr;
char opt[10];

int main() {
    scanf("%d", &N);
    arr.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int sz = 1;
    while(sz < N)
        sz *= 2;

    roots[1] = create(arr, 1, sz);

    scanf("%d", &M);
    while(M--) {
        scanf("%s", opt);
        if(opt[0] == 'c') {
            scanf("%d %d %d", &X, &Y, &Z);
            roots[CR++] = createFromTree(roots[X], Y, Z);
        } else {
            scanf("%d %d", &X, &Y);
            printf("%d\n", getValue(roots[X], Y));
        }
    }

    return 0;
}
