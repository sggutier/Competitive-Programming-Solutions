#include <bits/stdc++.h>
using namespace std;
const int LIM_N = 2e5 + 5;

int N ;
set <int> adj[LIM_N];
set <int> lens[LIM_N];

int main() {
    scanf("%d", &N);
    for(int i=1, a, b; i < N; i++) {
        scanf("%d%d", &a, &b);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    queue <int> Q ;
    for(int i=1; i <= N; i++)
        if((int) adj[i].size() == 1){
            Q.push(i);
            lens[i].insert(0);
            // printf("%d\n", i);
        }
    while((int) Q.size() > 1) {
        int pos = Q.front(); Q.pop();
        N --;
        // printf(">> %d\n", pos);
        if((int) lens[pos].size() > 1) {
            printf("-1\n");
            return 0 ;
        }
        int nxt = *adj[pos].begin();
        int len = *lens[pos].begin();
        adj[nxt].erase(pos);
        lens[nxt].insert(len+1);
        // printf("%d %d => %d\n", nxt, len, (int) adj[nxt].size());
        if((int) adj[nxt].size() == 1)
            Q.push(nxt);
    }
    int x = Q.front(); Q.pop();
    int sm = 0 ;
    if(lens[x].size() > 2) {
        printf("-1\n");
        return 0;
    }
    // printf("%d\n", x);
    for(const int a : lens[x])
        sm += a;
    while(sm % 2 == 0)
        sm /= 2;
    // printf("\n");
    printf("%d\n", sm);
}
