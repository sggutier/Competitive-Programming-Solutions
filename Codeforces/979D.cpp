#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 1e5 + 5;
const int LIM_Q = 318;
const int LIM_B = 17;

struct Nodo {
    Nodo *L = NULL, *R = NULL;
    int minV = LIM_N;
};

void insert(int x, Nodo *pos) {
    for(int pw = LIM_B - 1; pw >= 0; pw--) {
        pos->minV = min(pos->minV, x);
        auto &nxt = x & (1 << pw)? pos->R : pos->L;
        if(nxt == NULL)
            nxt = new Nodo();
        pos = nxt;
    }
    pos->minV = min(pos->minV, x);
}


int getMaxV(int x, int maxV, Nodo *pos) {
    int ans = 0 ;
    for(int pw = LIM_B - 1; pw >= 0; pw--) {
        if(!pos->L || (pos->R && (x & (1 << pw)) == 0 && pos->R->minV <= maxV)) {
            pos = pos->R;
            ans += 1 << pw;
        }
        else
            pos = pos->L;
    }
    return ans;
}

Nodo *rtVals[LIM_Q];
bool avil[LIM_N];
int minVs[LIM_Q];

void insertQuery() {
    int x ;
    scanf("%d", &x);
    avil[x] = true;
    for(int i=1; i < LIM_Q; i++)
        if(x % i == 0) {
            insert(x, rtVals[i]);
            minVs[i] = min(minVs[i], x);
        }
}

int findMaxDiv(const int x, const int k, const int maxV) {
    int ans = -1;
    for(int i=k; i <= maxV; i += k)
        if(avil[i]) {
            ans = max(ans, i ^ x);
        }
    return ans == -1? ans : ans ^ x;
}

void findQuery() {
    int w, k, s;
    scanf("%d%d%d", &w, &k, &s);
    s -= w;
    if(w % k || s <= 0) {
        printf("-1\n");
        return ;
    }
    printf("%d\n", k < LIM_Q?
           (minVs[k] <= s? getMaxV(w, s, rtVals[k]) : -1)
           : findMaxDiv(w, k, s));
}

int main() {
    for(int i=1; i < LIM_Q; i++) {
        rtVals[i] = new Nodo();
        minVs[i] = LIM_N;
    }
    int Q ;
    scanf("%d", &Q);
    for(int i=0, t; i < Q; i++) {
        scanf("%d", &t);
        if(t == 1) {
            insertQuery();
        }
        else {
            findQuery();
        }
    }
}
