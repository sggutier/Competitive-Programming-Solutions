#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = (1<<20) + 5;

int N, potN ;
int arr[limN], ordo[limN];
int crg[limN];
ll vals[25][2];

void mete(int pos, int nov) {
    for(; pos; pos-=(pos & -pos))
        crg[pos] += nov;
}

int saca(int pos) {
    int ans = 0;
    for(; pos<=potN; pos += (pos & -pos))
        ans += crg[pos];
    return ans;
}

ll invos(int l, int r, int L, int R) {
    for(int i=L; i<R; i++)
        mete(arr[i], 1);
    ll ans = 0;
    for(int i=l; i<r; i++)
        ans += saca(arr[i]+1);
    for(int i=L; i<R; i++)
        mete(arr[i], -1);
    return ans;
}

int main() {
    
    scanf("%d", &N);
    potN = 1<<N;
    for(int i=0; i<potN; i++) {
        scanf("%d", &arr[i]);
        ordo[i] = i;
    }
    sort(ordo, ordo+potN,
         [](const int a, const int b) {
             return arr[a] < arr[b]; });
    for(int i=0, u=-1, v, w=0; i<potN; i++) {
        v = arr[ordo[i]];
        if(v != u)
            w++;
        arr[ordo[i]] = w;
        u = v;
    }

    for(int p=0; p<N; p++) {
        int d = 1<<p;
        // printf("D es %d\n", d);
        for(int i=0, j=d, k=2*d; j<potN; i+=2*d, j+=2*d, k+=2*d) {
            vals[p][0] += invos(j, k, i, j);
            vals[p][1] += invos(i, j, j, k);
        }
    }

    int Q ;
    scanf("%d", &Q);
    for(int q; Q; Q--) {
        scanf("%d", &q);
        for(int i=0; i<q; i++)
            swap(vals[i][0], vals[i][1]);
        ll ans = 0;
        for(int i=0; i<N; i++)
            ans += vals[i][0];
        printf("%lld\n", ans);
    }
}
