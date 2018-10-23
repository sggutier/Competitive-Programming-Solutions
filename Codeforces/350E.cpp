#include <bits/stdc++.h>
using namespace std;
const int limN = 305;

bool unod[limN];
bool mdo[limN];

vector <int> ordo;

int gauss(int n) {
    return n*(n+1) / 2;
}

int main() {
    int N, E, D;
    scanf("%d%d%d", &N, &E, &D);
    for(int i=0, a; i<D; i++) {
        scanf("%d", &a); a--;
        unod[a] = true;
    }

    if(N == D) {
        printf("-1\n");
        return 0;
    }
    if(gauss(N-1) - (D-1) < E) {
        printf("-1\n");
        return 0;
    }

    for(int u=0; u<N; u++) {
        if(unod[u]) {
            // printf(">> %d\n", u+1);
            mdo[u] = true;
            ordo.push_back(u);
            break;
        }
    }
    for(int u=0; u<N; u++) {
        if(!unod[u]) {
            // printf(">> %d\n", u+1);
            mdo[u] = true;
            ordo.push_back(u);
            break;
        }
    }
    for(int i=0; i<N; i++)
        if(!mdo[i])
            ordo.push_back(i);

    for(int i=1; i<N; i++, E--)
        printf("%d %d\n", ordo[i-1] + 1, ordo[i] + 1);
    for(int j=2; j<N && E; j++)
        if(!unod[ordo[j]]) {
            printf("%d %d\n", ordo[0] + 1, ordo[j] + 1);
            E --;
        }
    for(int i=1; i<N && E; i++) {
        for(int j=i+2; j<N && E; j++) {
            printf("%d %d\n", ordo[i] + 1, ordo[j] + 1);
            E --;
        }
    }
    
}
