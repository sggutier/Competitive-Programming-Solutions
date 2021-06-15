#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

int N, X;
vector <int> adj[limN];
int patr[limN];
int disFonMemo[limN];
int dep[limN];

int ordena(int pos, int ant=-1, int d=0) {
    int ans = 0;
    dep[pos] = d;
    patr[pos] = ant;
    for(const int &sig:adj[pos]) {
        if(sig!=ant) {
            ans = max(ans, ordena(sig, pos, d+1) + 1);
        }
    }
    return disFonMemo[pos] = ans;
}

int main() {
    scanf("%d%d", &N, &X);
    for(int i=1; i<N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ordena(1);

    int ans = 0, cnt = 0;
    while(cnt < dep[X]) {
        ans = max(ans, 2*(dep[X] + disFonMemo[X]));
        X = patr[X];
        cnt ++;
    }

    printf("%d\n", ans);
}
