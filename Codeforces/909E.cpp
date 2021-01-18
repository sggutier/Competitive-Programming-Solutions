#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 2e5 + 5 ;

int N ;
int tp[LIM_N];
int depCnt[LIM_N];
vector <int> adj[LIM_N];

void vacia(queue <int> &Q, queue <int> &R, const int t) {
    while(!Q.empty()) {
        int pos = Q.front(); Q.pop();
        for(const int nxt : adj[pos]) {
            depCnt[nxt] --;
            if(depCnt[nxt]) continue;
            (tp[nxt]==t? Q : R).push(nxt);
        }
    }
}

int main() {
    int E ;
    int ans = 0 ;

    scanf("%d%d", &N, &E);
    for(int i=0; i < N; i++)
        scanf("%d", &tp[i]);
    for(int i=0, a, b; i < E; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        depCnt[b] ++;
    }

    queue <int> Q[2];
    for(int i=0; i < N; i++)
        if(depCnt[i] == 0) {
            adj[N].push_back(i);
            depCnt[i] ++ ;
        }
    Q[1].push(N);

    while(!Q[1].empty()) {
        vacia(Q[1], Q[0], 0);
        if(Q[0].empty()) break;
        ans ++ ;
        vacia(Q[0], Q[1], 1);
    }

    printf("%d\n", ans);
}
