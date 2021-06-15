#include <bits/stdc++.h>
using namespace std;

int query(int q) {
    printf("%d\n", q);
    fflush(stdout);
    scanf("%d", &q);
    if(q==-2 || q==0) {
        exit(0);
    }
    return q;
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int sgns[50];

    for(int i=0; i<n; i++)
        sgns[i] = -query(1);
    int ini=2, fin=m, pv;
    for(int i=0; ini < fin; i = (i+1)%n) {
        pv = (ini+fin)/2;
        if(sgns[i] * query(pv) < 0)
            ini = pv+1;
        else
            fin = pv-1;
    }
    query(ini);
}
