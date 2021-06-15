#include <bits/stdc++.h>
using namespace std;
const int limN = 3e5 + 5;
typedef long long ll;

int N, F, B;
vector <int> adj[limN];
ll chldCnt[limN];

ll cuenta(int pos=F, int ant=0) {
    ll &ans = chldCnt[pos];
    ans++;
    for(const int &sig : adj[pos])
        if(sig != ant) {
            ll w = cuenta(sig, pos);
            if(w==0 && ant)
                return 0;
            ans += w;
        }
    // printf("%d => %lld\n", pos, chldCnt[pos]);
    return pos==B? 0 : ans;
}

int main() {
    scanf("%d%d%d", &N, &F, &B);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cuenta();

    printf("%lld\n", ((long long) N)*N - N - chldCnt[F]*chldCnt[B] );
}
