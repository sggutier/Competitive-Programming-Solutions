#include <bits/stdc++.h>
using namespace std;
const int limN = 3005;
typedef pair<int,int> pii;
typedef pair<pii, int> piii;
#define f first
#define s second
const int inf = 1e9;

int cnt[limN][limN];
set <pii> wo[limN];
vector <int> ida[limN], ven[limN];

int main() {
    int N, E;
    long long ans = 0;

    scanf("%d%d", &N, &E);
    for(int i=0; i<E; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--, b--;
        ida[a].push_back(b);
        ven[b].push_back(a);
    }

    for(int i=0; i<N; i++) {
        for(int j=ida[i].size()-1; j>=0; j--) {
            for(int k=j-1; k>=0; k--) {
                int p = ida[i][j], q = ida[i][k];
                if(p > q)
                    swap(p, q);
                wo[i].insert(pii(p, q));
                cnt[p][q] ++;
                // printf(">> %d %d %d\n", i+1, p+1, q+1);
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=ven[i].size()-1; j>=0; j--) {
            for(int k=j-1; k>=0; k--) {
                int p = ven[i][j], q = ven[i][k];
                if(p > q)
                    swap(p, q);
                // printf("<< %d %d %d\n", i+1, p+1, q+1);
                ans += cnt[p][q] - wo[i].count(pii(p, q));
            }
        }
    }

    printf("%lld\n", ans);
}
