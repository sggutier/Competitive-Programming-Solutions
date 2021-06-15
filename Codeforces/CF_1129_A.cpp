#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second
const int limN = 1e5 + 5;

int N, M ;
int cnt[limN];
int minT[limN];

int proco(int ini) {
    int ans = 0 ;
    for(int i=0, w; i<N; i++) {
        w = (i + ini) % N;
        if(!cnt[w]) continue;
        ans = max(ans, (cnt[w]-1) * N + (w + N - ini) % N + minT[w]);
    }
    return ans;
}

int main() {

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        minT[i] = 1e9 ;
    for(int i=0, a, b; i<M; i++) {
        scanf("%d%d", &a, &b);
        a--, b--;
        cnt[a] ++;
        minT[a] = min(minT[a], (b + N - a) % N);
    }

    for(int i=0; i<N; i++)
        printf("%d ", proco(i));
    printf("\n");
}
