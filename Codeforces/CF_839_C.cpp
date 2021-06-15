#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

vector <int> adj[limN];

double espero(int pos=1, int ant=-1) {
    int ng = 0;
    double sumo = 0;
    for(const int &sig:adj[pos]) {
        if(sig==ant) continue;
        ng ++;
        sumo += 1 + espero(sig, pos);
    }
    return ng? sumo/ng : 0;
}

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("%.9lf\n", espero());
}
