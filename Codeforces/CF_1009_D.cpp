#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 +5;

vector < int > adj[limN];

int main() {
    int N, E;
    scanf("%d%d", &N, &E);

    if(E < N-1) {
        printf("Impossible\n");
        return 0;
    }

    for(int i=2; i<=N; i++) {
        adj[i].push_back(1);
    }
    E -= N-1;
    for(int i=2; i<=N && E; i++) {
        for(const int cp : adj[i]) {
            for(int j=i+cp; j<=N && E; j+=i)
                E--, adj[j].push_back(i);
            if(!E)
                break;
        }
    }

    if(E) {
        printf("Impossible\n");
        return 0;
    }

    printf("Possible\n");
    for(int i=1; i<=N; i++) {
        for(const int cp : adj[i])
            printf("%d %d\n", i, cp);
    }
}
