#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
typedef long long ll;

struct lzstNode {
    lzstNode *L, *R;
    ll sum, crg;
};

int N ;
int trCnt = 0;
lzstNode tree[limN];

void add(const ll crg, const int a, const int b, const int l=0, const int r=N, lzstNode* nod=&tree[0]) {    
    if(b<=l || r<=a)
        return;
    if(a <= l && r <= b) {
        nod->crg += crg;
        return ;
    }
    int piv = (l+r)/2;
    if(nod->L == NULL)
        nod->L = &tree[trCnt++];
    if(nod->R == NULL)
        nod->R = &tree[trCnt++];
    add(crg, a, b, l, piv+1, nod->L);
    add(crg, a, b, piv, r, nod->R);
}

int main() {
}
