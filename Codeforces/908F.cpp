#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
#define f first
#define s second
const int limN = 3e5 + 5;
const int inf = 1e9 + 1;

int N;
int ps[limN];
char col[limN];

ll mst(char forb) {
    bitset <limN> usd;
    priority_queue <pli> Q ;
    ll ans = 0;
    for(int i=0; i<N; i++)
        if(col[i] == 'R')
            Q.push({0, i});
    while(!Q.empty()) {
        ll d = -Q.top().f;
        int pos = Q.top().s;
        Q.pop();
        if(usd[pos]) continue ;
        usd[pos] = true;
        ll s = 0;
        if(col[pos] == forb)
            s = d;
        else
            ans += d;
        if(pos)
            Q.push({-s - (ps[pos] - ps[pos-1]), pos-1});
        if(pos+1 < N)
            Q.push({-s - (ps[pos+1] - ps[pos]), pos+1});
    }
    return ans;
}

bool hasas[300];
tuple <int, int, int> ccs() {
    int minos[300], maxos[300];
    minos['R'] = minos['G'] = minos['B'] = inf;
    maxos['R'] = maxos['G'] = maxos['B'] = -inf;
    for(int i=0; i<N; i++) {
        int c = col[i];
        minos[c] = min(minos[c], ps[i]);
        maxos[c] = max(maxos[c], ps[i]);
    }
    hasas['R'] = minos['R'] != inf;
    hasas['G'] = minos['G'] != inf;
    hasas['B'] = minos['B'] != inf;
    return {(maxos['R'] - minos['R']) % (2*inf),
            (maxos['G'] - minos['G']) % (2*inf),
            (maxos['B'] - minos['B']) % (2*inf)};
}

int main() {
    char tmp[5];
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%s", &ps[i], tmp);
        col[i] = tmp[0];
        if(col[i] == 'R')
            col[i] = 'G';
        else if(col[i] == 'G')
            col[i] = 'R';
    }

    int sr, sg, sb;
    tie(sr, sg, sb) = ccs();

    if(hasas['R'] == 0) {
        printf("%d\n", sg + sb);
        return 0 ;
    }

    if(hasas['G'] == 0 || hasas['B'] == 0) {
        printf("%d\n", ps[N-1] - ps[0]);
        return 0 ;
    }

    printf("%lld\n", sr + mst('G') + mst('B'));
}
