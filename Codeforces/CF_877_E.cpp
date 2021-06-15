#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

int N;

struct SegmTree {
    int vals[limN*6];
    vector<bool> crg;
    void inita(const int *arr, const int pos, const int l, const int r) {
        if(l+1 == r) {
            vals[pos] = arr[l];
            // printf("En %d (%d %d) se pone %d\n", pos, l+1, r, vals[pos]);
            return;
        }
        if(l >= r)
            return;
        int piv = (l+r)/2;
        inita(arr, pos*2, l, piv);
        inita(arr, pos*2+1, piv, r);
        vals[pos] = vals[pos*2] + vals[pos*2+1];
        // printf("En %d (%d %d) se pone %d\n", pos, l+1, r, vals[pos]);
    }

    void push(const int pos, const int l, const int r) {
        if(!crg[pos]) return;
        crg[pos] = 0;
        crg[pos*2] = !crg[pos*2];
        crg[pos*2+1] = !crg[pos*2+1];
        vals[pos] = r-l-vals[pos];
    }
    
    void inita(const int *arr) {
        crg.resize(N*6);
        inita(arr, 1, 0, N);
    }
    void flipa(const int lk, const int rk, const int pos=1, const int l=0, const int r=N) {
        // printf("fliprq con %d ||| %d %d %d %d\n", pos, lk, rk, l, r);
        push(pos, l, r);
        if(l >= r || rk <= l || r <= lk)
            return ;
        if(lk <= l && r <= rk) {
            crg[pos*2] = !crg[pos*2];
            crg[pos*2+1] = !crg[pos*2+1];
            // int piv = (l+r)/2;
            // if(l+1 != r) {
            //     flipa(lk, rk, pos*2, l, piv);
            //     flipa(lk, rk, pos*2+1, piv, r);
            // }
            vals[pos] = r-l-vals[pos];
            return;
            // printf("El nodo %d (%d %d) ahora tiene %d\n", pos, l+1, r, vals[pos]);
            // return vals[pos];
        }
        int piv = (l+r)/2;
        flipa(lk, rk, pos*2, l, piv);
        flipa(lk, rk, pos*2+1, piv, r);
        vals[pos] = vals[pos*2] + vals[pos*2+1];
        // printf("El nodo %d (%d %d) ahora tiene %d\n", pos, l+1, r, vals[pos]);
        // return vals[pos];
    }
    int query(const int lk, const int rk, const int pos=1, const int l=0, const int r=N) {       
        if(l>=r || rk <= l || r <= lk)
            return 0;
        push(pos, l, r);
        if(lk <= l && r <= rk) {
            // printf("Desde %d (%d %d) se saca %d\n", pos, l+1, r, vals[pos]);
            return vals[pos];
        }
        int piv = (l+r)/2;
        // printf("Desde %d (%d %d) se saca %d\n", pos, l+1, r, query(lk, rk, pos*2, l, piv) + query(lk, rk, pos*2+1, piv, r));
        return query(lk, rk, pos*2, l, piv) + query(lk, rk, pos*2+1, piv, r);
    }
};

vector <int> adj[limN];
int aprIni[limN], aprFin[limN];
SegmTree st;

void dfs(const int pos=0) {
    aprIni[pos] = aprFin[pos] = N++;
    for(const int &sig:adj[pos]) {
        dfs(sig);
        aprFin[pos] = max(aprFin[pos], aprFin[sig]);
    }    
    // printf("Las aprs de %d => %d %d\n", pos+1, aprIni[pos]+1, aprFin[pos]+1);
}

int main() {
    int vals[limN];
    char tmp[7];

    scanf("%d", &N);
    for(int i=1, p; i<N; i++) {
        scanf("%d", &p);
        adj[p-1].push_back(i);
    }
    N = 0;
    dfs();
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        vals[aprIni[i]] = a;
    }
    st.inita(vals);

    int Q, a ;
    for(scanf("%d", &Q); Q; Q--) {
        scanf("%s%d", tmp, &a);
        a--;
        // printf("QUERRYYYYY : %s %d => %d %d\n", tmp, a+1, aprIni[a]+1, aprFin[a]+1);
        if(tmp[0]=='g')
            printf("%d\n", st.query(aprIni[a], aprFin[a]+1));
        else
            st.flipa(aprIni[a], aprFin[a]+1);
    }
}
