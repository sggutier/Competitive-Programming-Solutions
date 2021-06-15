#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int mod2 = 1e8 + 7;
const int limN = 3e5 + 5;

tuple <pair<int, int>, int, int> proca(char* c) {
    int len = 0, rs = 0;
    long long hs = 0, hs2 = 0;
    for(; *c; c++) {
        len ++;
        hs = (hs*27 + (tolower(*c)-'a'+1)) % mod;
        hs2 = (hs*27 + (tolower(*c)-'a'+1)) % mod2;
        if(tolower(*c) == 'r')
            rs ++;
    }
    return {{hs, hs2}, rs, len};
}

char _str[2*limN];
vector <int> adj[limN];
pair <int, int> apt[limN];
int dep[limN], minDep[limN];
bool actv[limN];
int color[limN];
pair <int, int> aptGrp[limN];
stack <int> stk;

void tarjan(const int pos) {
    static int taCnt = 0;
    if(dep[pos])
        return;
    actv[pos] = true;
    dep[pos] = minDep[pos] = ++taCnt;
    stk.push(pos);
    for(const int &sig:adj[pos]) {
        tarjan(sig);
        if(actv[sig])
            minDep[pos] = min(minDep[pos], minDep[sig]);
    }
    if(minDep[pos] != dep[pos])
        return;
    int w ;
    aptGrp[pos] = apt[pos];
    // printf("Grupo con %d => ", pos);
    do {
        w = stk.top(); stk.pop();
        color[w] = pos;
        actv[w] = false;
        aptGrp[pos] = min(aptGrp[pos], apt[w]);
        for(const int &sig:adj[w]) {
            if(!actv[sig] && color[sig]!=pos) {
                aptGrp[pos] = min(aptGrp[pos], aptGrp[color[sig]]);
            }
        }
        // printf("%d ", w);
    } while(w!=pos) ;
    // printf("\n");
}

int main() {
    map <pair<int, int>, int> ids;
    int N, E, W = 0 ;
    long long tl = 0, tr = 0;
    pair <int,int> ans(1e9, 1e9);
    int wds[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        pair <int,int> _x;
        int x, y, z;
        scanf("%s", _str);
        tie(_x, y, z) = proca(_str);
        if(ids.count(_x)==0) 
            ids[_x] = W++;
        x = ids[_x];
        apt[x] = {y, z};
        wds[i] = x;
        // printf("%d ", wds[i]);
    }
    // printf("\n");

    scanf("%d", &E);
    for(int i=0; i<E; i++) {
        int y, z, q, r, x, p;
        pair <int, int> _x, _p;
        scanf("%s", _str);
        tie(_x, y, z) = proca(_str);
        if(ids.count(_x)==0)
            ids[_x] = W++;
        x = ids[_x];
        apt[x] = {y, z};
        scanf("%s", _str);
        tie(_p, q, r) = proca(_str);
        if(ids.count(_p)==0)
            ids[_p] = W++;
        p = ids[_p];
        apt[p] = {q, r};
        adj[x].push_back(p);
        // printf("Arista de %d a %d\n", x, p);
    }

    for(int i=0; i<W; i++) {
        tarjan(i);
    }

    for(int i=0; i<N; i++) {
        int c = color[wds[i]];
        tr += aptGrp[c].first;
        tl += aptGrp[c].second;
    }

    printf("%lld %lld\n", tr, tl);
}
