#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LIM_N = 1e5 + 5;

int N ;
ll xs[LIM_N], fs[LIM_N];
ll ds[LIM_N];

int main() {
    set <int> ans ;
    set <ll> acms;
    ll tt = 0;

    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%lld", &fs[i]);
    }
    for(int i=0; i < N; i++) {
        scanf("%lld", &xs[i]);
        ds[i] = fs[i] - xs[i];
    }
    if(N == 1) {
        printf("1\n1\n");
        return 0 ;
    }
    for(int i=0; i < N; i++) {
        tt += ds[i];
        // printf("%lld ", tt);
        acms.insert(tt);
    }
    // printf("|");
    for(int i=0; i < N; i++) {
        // printf(" %lld", tt);
        auto it = acms.find(tt);
        acms.erase(it);
        if(*acms.begin() >= tt) {
            // printf("*");
            ans.insert(i);
        }
        acms.insert(tt);
        tt += ds[i];
    }
    // printf("\n");

    reverse(fs, fs+N);
    reverse(xs, xs+N);
    xs[N] = xs[0];
    for(int i=0; i < N; i++) {
        xs[i] = xs[i+1];
        ds[i] = fs[i] - xs[i];
    }
    acms.clear();
    for(int i=0; i < N; i++) {
        tt += ds[i];
        // printf("%lld ", tt);
        acms.insert(tt);
    }
    // printf("| ");
    for(int i=0; i < N; i++) {
        // printf(" %lld", tt);
        auto it = acms.find(tt);
        acms.erase(it);
        if(*acms.begin() >= tt) {
            // printf("*");
            ans.insert(N-1-i);
        }
        acms.insert(tt);
        tt += ds[i];
    }
    // printf("\n");
    printf("%d\n", (int) ans.size());
    for(const int a : ans)
        printf("%d ", a + 1);
}
