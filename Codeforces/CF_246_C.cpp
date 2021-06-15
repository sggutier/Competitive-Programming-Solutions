#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, int> pli;
#define f first
#define s second
const int limN = 1e5 + 5;
const ll inf = 1e18;

int N;
ll vals[limN];
int cols[limN];
ll maxS[limN];

void query(ll a, ll b) {
    int ansA = 1, ansB = 2;
    for(int i=1; i<=N+1; i++)
        maxS[i] = -inf;
    for(int i=1, c; i<=N; i++) {
        c = cols[i];
        maxS[c] = max(max(maxS[c], maxS[c] + vals[i]*a),
                      max(0LL, maxS[ansA==c? ansB : ansA]) + vals[i]*b);
        if(c!=ansA && c!=ansB && maxS[c] > maxS[ansB])
            ansB = c;
        if(maxS[ansA] < maxS[ansB])
            swap(ansA, ansB);
        // printf("\t%lld %lld\n", maxS[ansA], maxS[ansB]);
    }
    printf("%lld\n", max(0LL, maxS[ansA]));
}

int main() {
    int Q ;
    int a, b ;

    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++)
        scanf("%lld", &vals[i]);
    for(int i=1; i<=N; i++)
        scanf("%d", &cols[i]);
    while(Q--) {
        scanf("%d%d", &a, &b);
        query(a, b);
    }
}
