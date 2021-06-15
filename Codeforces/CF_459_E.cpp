#include <bits/stdc++.h>
using namespace std;
const int limN = 3e5 + 5;
typedef pair<int,int> par;
typedef pair<int,par> tri;
#define f first
#define s second

int maxL[limN];

int main() {
    int N, E;
    tri ars[limN];

    scanf("%d%d", &N, &E);
    for(int i=0; i<E; i++) {
        scanf("%d%d%d", &ars[i].s.f, &ars[i].s.s, &ars[i].f);
        ars[i].s.f --, ars[i].s.s--;
    }
    sort(ars, ars+E);

    for(int i=E-1, j; i>=0; i=j) {
        map <int, int> au;
        for(j=i; j>=0 && ars[j].f==ars[i].f; j--) {
            au[ars[j].s.f] ;
            auto it = au.find(ars[j].s.f);
            it->second = max(it->second, maxL[ars[j].s.s]+1);
        }
        for(const par &a:au) {
            maxL[a.first] = max(maxL[a.first], a.second);
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++)
        ans = max(ans, maxL[i]);

    printf("%d\n", ans);
}
